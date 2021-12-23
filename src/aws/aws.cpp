#include "aws.h"

void AWS::begin(char endpoint[], uint16_t port, char device_name[])
{
  dev_name = device_name;
  keys.begin();
  configureTLSClient();
  configureMQTTClient(endpoint, port, device_name);
}

void AWS::configureTLSClient()
{
  tls_client.setCACert(keys.getRootCA());
  tls_client.setPrivateKey(keys.getPrivateKey());
  tls_client.setCertificate(keys.getDeviceCert());
}

void AWS::configureMQTTClient(char endpoint[], uint16_t port, char device_name[])
{
  mqtt_client.begin(endpoint, port, tls_client);

  while (!mqtt_client.connect(device_name))
  {
    delay(100);
  }

  if (!mqtt_client.connected())
  {
    return;
  }
}

void AWS::publish(char topic[], const char *payload)
{
  while (!mqtt_client.connect(dev_name))
  {
    delay(100);
  }
  mqtt_client.publish(topic, payload);
  mqtt_client.loop();
}

void AWS::subscribe(char topic[])
{
  mqtt_client.subscribe(topic);
}