#include "iot-json-parser.h"

char *Parser::parseData(char sensor_type[], char unit[], float value)
{
  doc["sensor"] = sensor_type;
  doc["value"] = value;
  doc["unit"] = unit;
  doc["time"] = millis();
  serializeJson(doc, json_buffer);
  return json_buffer;
}