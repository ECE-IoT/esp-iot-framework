#include "keys.h"

void Keys::begin()
{
  spiffs.spiffsBeginn();
  private_key_ = spiffs.readSpiffs("/esp32-d1mini-01.private.key");
  device_cert_ = spiffs.readSpiffs("/esp32-d1mini-01.cert.pem");
  root_ca_ = spiffs.readSpiffs("/root-CA.crt");
}

char *Keys::getPrivateKey()
{
  return private_key_;
}

char *Keys::getDeviceCert()
{
  return device_cert_;
}

char *Keys::getRootCA()
{
  return root_ca_;
}
