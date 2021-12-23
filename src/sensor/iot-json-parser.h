#ifndef VERT_PROT_JSON
#define VERT_PROT_JSON

#include <Arduino.h>
#include <ArduinoJson.h>

class Parser
{
private:
  StaticJsonDocument<100> doc;
  char json_buffer[100];

public:
  char *parseData(char sensor_type[], char unit[], float value);
};

#endif