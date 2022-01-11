#ifndef ESP_IOT_LOGGER
#define ESP_IOT_LOGGER

#include "spiffs.h"
#include <Arduino.h>

#define LOG_FILE "/log_file.txt"

class EspLogger
{
public:
  EspSpiffs spiffs;
  void logBegin();
  void logError(char* message);
  void logInfo(char* message);
};

#endif