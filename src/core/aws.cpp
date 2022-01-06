#include "aws.h"

void AWS::begin(char endpoint[], uint16_t port, char device_name[])
{
  dev_name = device_name;
  keys.begin();
  configureTLSClient();
}

void AWS::configureTLSClient()
{
  tls_client.setCACert(keys.getRootCA());
  tls_client.setPrivateKey(keys.getPrivateKey());
  tls_client.setCertificate(keys.getDeviceCert());
}