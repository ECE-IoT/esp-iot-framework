#ifndef ESP_IOT_SPIFFS
#define ESP_IOT_SPIFFS

#include <Arduino.h>
#include <SPIFFS.h>

class EspSpiffs
{
public:
  void spiffsBeginn();
  char* readSpiffs(char* path);
  void printLog(char* path);
  void appendLog(char* message, char* path);
  void createFile(char* path);
};

#endif