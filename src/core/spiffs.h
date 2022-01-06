#ifndef ESP_IOT_SPIFFS
#define ESP_IOT_SPIFFS

#include <Arduino.h>
#include <SPIFFS.h>

class EspSpiffs
{
public:
  void spiffsBeginn();
  char* readSpiffs(String path);
  void appendLog(String message, String path);
  void createFile(String path);
};

#endif