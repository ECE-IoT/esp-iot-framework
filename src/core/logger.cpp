#include "logger.h"

EspLogger EspLogger::esp_logger_instance;

void EspLogger::logBegin(uint8_t log_level, uint8_t log_output_level)
{
  log_level_ = log_level;
  log_output_level_ = log_output_level;
  spiffs.spiffsBeginn();
  esp_ntp = EspNTP::getInstance();

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
    /*manage log file rotation*/
    if(row_cnt_ >= LOG_FILE_MAX_ROWS)
    {
      row_cnt_ = 0;
      actual_log_file_++;
      if(actual_log_file_ >= LOG_FILES_NUMBER)
      {
        actual_log_file_ = 0;
      }
      spiffs.createFile((char*)log_files_[actual_log_file_]);
    }
    spiffs.appendLog(message, (char*)log_files_[actual_log_file_]);
    row_cnt_++;
  }
}

void EspLogger::logFatal(char* message)
{
  if(log_level_ >= LOG_LEVEL_FATAL)
  {
    EspLogger::logBuildMessage(LOG_LEVEL_FATAL_SPECIFIER, message);
    EspLogger::logPrint(log_message_buffer_);
  }
}

void EspLogger::logError(char* message)
{
  if(log_level_ >= LOG_LEVEL_ERROR)
  {
    EspLogger::logBuildMessage(LOG_LEVEL_ERROR_SPECIFIER, message);
    EspLogger::logPrint(log_message_buffer_);
  }
}

void EspLogger::logWarning(char* message)
{
  if(log_level_ >= LOG_LEVEL_WARNING)
  {
    EspLogger::logBuildMessage(LOG_LEVEL_WARNING_SPECIFIER, message);
    EspLogger::logPrint(log_message_buffer_);
  }
}

void EspLogger::logInfo(char* message)
{
  if(log_level_ >= LOG_LEVEL_INFO)
  {
    EspLogger::logBuildMessage(LOG_LEVEL_INFO_SPECIFIER, message);
    EspLogger::logPrint(log_message_buffer_);
  }
}

void EspLogger::logDebug(char* message)
{
  if(log_level_ >= LOG_LEVEL_DEBUG)
  {
    EspLogger::logBuildMessage(LOG_LEVEL_DEBUG_SPECIFIER, message);
    EspLogger::logPrint(log_message_buffer_);
  }
}

void EspLogger::logBuildMessage(char* specifier, char* message)
{
  strcpy(log_message_buffer_, specifier);
  strcat(log_message_buffer_, message);
  strcat(log_message_buffer_, "  timestamp: ");
  strcat(log_message_buffer_, esp_ntp->getValueChar());
}