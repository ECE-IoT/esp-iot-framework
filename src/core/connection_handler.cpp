#include "connection_handler.h"

void EspConnectionHandler::setup()
{
  EspMqttConfig mqtt_config;
  esp_mqtt_ = EspMqtt::getInstance();
  esp_config_ = EspConfig::getInstance();

  if(esp_mqtt_ == NULL)
  {
    // TODO include error handling (e.g. write to log file)
    return;
  }

  if(esp_config_ == NULL)
  {
    // TODO include error handling (e.g. write to log file)
    return;
  }
  
  esp_wifi_.beginWifi(esp_config_->getWifiSSID() , esp_config_->getWifiPSWD());

  while (esp_wifi_.statusWifi() != WL_CONNECTED)
  {
    /*TODO nochmal drüber denken und vl mit einer maximalen Zeit*/
    /*Wird im Setup aufgerufen und würd die Lopp nicht blockieren*/
  }

  // fill struct for mqtt
  mqtt_config.server_address = esp_config_->getAwsUrl();
  mqtt_config.device_id = esp_config_->getDeviceID();
  mqtt_config.subscribe_topic = esp_config_->getMqttSubTopic();
  mqtt_config.publish_topic =  esp_config_->getMqttPubTopic();
  mqtt_config.port =  esp_config_->getAwsPort();
  mqtt_config.tls_client =  tls_client_;

  esp_mqtt_->setup(mqtt_config);

}