#include "esp_logger.hpp"

void EspLogger::logBegin()
{
  Serial.println(spiffs.readSpiffs(LOG_FILE));

  spiffs.createFile(LOG_FILE); // create / erases the existing file
}

void EspLogger::logError(String message)
{
  String error_message = "ERROR "+ message + "  timestamp: "+ millis();
  spiffs.appendLog(error_message, LOG_FILE);

}

void EspLogger::logInfo(String message)
{
  String info_message = "INFO "+ message + "  timestamp: "+ millis();
  spiffs.appendLog(info_message, LOG_FILE);
}