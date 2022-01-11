#include "logger.h"

void EspLogger::logBegin()
{
  Serial.println(spiffs.readSpiffs(LOG_FILE));

  spiffs.createFile(LOG_FILE); // create / erases the existing file
}

void EspLogger::logError(String message)
{
  String error_message = "ERROR " + message + "  timestamp: " + millis();
  char error_message_char[error_message.length()];
  error_message.toCharArray(error_message_char, error_message.length());

  spiffs.appendLog(error_message_char, LOG_FILE);
}

void EspLogger::logInfo(String message)
{
  String info_message = "INFO " + message + "  timestamp: " + millis();
  char info_message_char[info_message.length()];
  info_message.toCharArray(info_message_char, info_message.length());

  spiffs.appendLog(info_message_char, LOG_FILE);
}