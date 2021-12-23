#ifndef VERT_PROT_LOGGER
#define VERT_PROT_LOGGER
#include <Arduino.h>
#include "esp_spiffs.hpp"

#define LOG_FILE "/log_file.txt"

class EspLogger
{
  public:
  EspSpiffs spiffs;
  void logBegin();
  void logError(String message);
  void logInfo(String message);
};
#endif