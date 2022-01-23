#include "logger.h"

void EspLogger::logBegin(uint8_t log_level, uint8_t log_output_level)
{
  log_level_ = log_level;
  log_output_level_ = log_output_level;

  if(log_output_level_ == LOG_OUTPUT_SERIAL_BEGIN || log_output_level_ == LOG_OUTPUT_SERIAL_DIRECT_BEGIN)
  {
    spiffs.printLog(LOG_FILE1);
    spiffs.printLog(LOG_FILE2);
    spiffs.printLog(LOG_FILE3);
    
  }
}

void EspLogger::logPrint(char* message)
{
  if(log_output_level_ == LOG_OUTPUT_SERIAL_DIRECT || log_output_level_ == LOG_OUTPUT_SERIAL_DIRECT_BEGIN)
  {
    Serial.println(message);
  }
  if(log_output_level_ == LOG_OUTPUT_SERIAL_BEGIN || log_output_level_ == LOG_OUTPUT_SERIAL_DIRECT_BEGIN)
  {
    // TODO write file rotation
  }
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