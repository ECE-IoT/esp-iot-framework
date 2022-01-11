#include "logger.h"

void EspLogger::logBegin()
{
  Serial.println(spiffs.readSpiffs(LOG_FILE));

  spiffs.createFile(LOG_FILE); // create / erases the existing file
}

void EspLogger::logError(char* message)
{
  char* error_message = "ERROR ";
  strcat(error_message, message);
  strcat(error_message, "  timestamp: ");
  strcat(error_message, (char*)millis());


  // String error_message = "ERROR " + message + "  timestamp: " + millis();
  // char error_message_char[error_message.length()];
  // error_message.toCharArray(error_message_char, error_message.length());

  spiffs.appendLog(error_message, LOG_FILE);
}

void EspLogger::logInfo(char* message)
{
  char* info_message = "INFO ";
  strcat(info_message, message);
  strcat(info_message, "  timestamp: ");
  strcat(info_message, (char*)millis());


  // String info_message = "INFO " + message + "  timestamp: " + millis();
  // char info_message_char[info_message.length()];
  // info_message.toCharArray(info_message_char, info_message.length());

  spiffs.appendLog(info_message, LOG_FILE);
}