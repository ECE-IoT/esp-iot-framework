#include "connection_handler.h"

void EspConnectionHandler::setup()
{
  EspMqttConfig mqtt_config;
  esp_mqtt_   = EspMqtt::getInstance();
  esp_config_ = EspConfig::getInstance();
  esp_ntp_    = EspNTP::getInstance();

  if (esp_mqtt_ == NULL)
  {
    // TODO include error handling (e.g. write to log file)
    return;
  }

  if (esp_config_ == NULL)
  {
    // TODO include error handling (e.g. write to log file)
    return;
  }

  if (esp_ntp_ == NULL)
  {
    // TODO include error handling (e.g. write to log file)
    return;
  }

  esp_wifi_.beginWifi(esp_config_->getWifiSSID(), esp_config_->getWifiPSWD());

  while (esp_wifi_.statusWifi() != WL_CONNECTED)
  {
    /*TODO nochmal drüber denken und vl mit einer maximalen Zeit*/
    /*Wird im Setup aufgerufen und würd die Lopp nicht blockieren*/
  }

  // fill struct for mqtt
  mqtt_config.server_address = esp_config_->getAwsUrl();
  mqtt_config.device_id      = esp_config_->getMqttPubTopic();
  ; // esp_config_->getDeviceID();
  mqtt_config.subscribe_topic = esp_config_->getMqttSubTopic();
  mqtt_config.publish_topic   = esp_config_->getMqttPubTopic();
  mqtt_config.port            = esp_config_->getAwsPort();

  esp_ntp_->setup(TZ_Europe_Vienna);
  esp_mqtt_->setup(&mqtt_config);
}

connection_states EspConnectionHandler::runHandler()
{
  switch (state_)
  {
  /*connect to wifi*/
  case CONNECT_WIFI:

    if (esp_wifi_.statusWifi() == WL_CONNECTED)
    {
      state_                   = CONNECT_MQTT;
      wifi_reconnect_attempted = false;
    }
    else if (wifi_reconnect_attempted == false)
    {
      esp_wifi_.reconnectWifi();
      wifi_reconnect_attempted = true;
    }
    break;

  /*connect to mqtt*/
  case CONNECT_MQTT:

    if (esp_wifi_.statusWifi() == WL_CONNECTED)
    {
      if (esp_mqtt_->connect() == true)
      {
        state_ = CONNECTED;
        this->runInitToAWS();
      }
    }
    else
    {
      state_ = CONNECT_WIFI;
    }
    break;

  /*connected*/
  case CONNECTED:

    if (esp_wifi_.statusWifi() == WL_CONNECTED)
    {
      if (esp_mqtt_->connect() != true)
      {
        state_ = CONNECT_MQTT;
      }
    }
    else
    {
      state_ = CONNECT_WIFI;
    }
    break;
  }

  return state_;
}

void EspConnectionHandler::runInitToAWS()
{
  char* serialized_json_message =
      this->esp_json_.serializeForSensor(0.0, "NULL", "INIT_SENSOR", "INIT_SENSOR", this->esp_ntp_->getValue());
  this->esp_mqtt_->publish("init", serialized_json_message);
}