#ifndef ESP_IOT_LOGGER
#define ESP_IOT_LOGGER

#include "spiffs.h"
#include "ntp.h"
#include <Arduino.h>

#define LOG_FILE1 "/log_file1.txt"
#define LOG_FILE2 "/log_file2.txt"
#define LOG_FILE3 "/log_file3.txt"
#define LOG_FILES_NUMBER 3 /*Total number of Log Files*/
#define LOG_FILE_MAX_ROWS 100 /*Maximum rows of one log file*/

/**
 * LOG LEVELS 
 * 
 */
#define LOG_LEVEL_OFF 0     /*no logging*/
#define LOG_LEVEL_FATAL 1   /*Designates very severe error events that will presumably lead the application to abort*/
#define LOG_LEVEL_ERROR 2   /*Designates error events that might still allow the application to continue running*/
#define LOG_LEVEL_WARNING 3 /*Designates potentially harmful situations*/
#define LOG_LEVEL_INFO 4    /*Designates informational messages that highlight the progress of the application at coarse-grained level.*/
#define LOG_LEVEL_DEBUG 5   /*Designates fine-grained informational events that are most useful to debug an application.*/
/**
 * LOG LEVELS Specifier
 * 
 */
#define LOG_LEVEL_FATAL_SPECIFIER "FATAL "
#define LOG_LEVEL_ERROR_SPECIFIER "ERROR "
#define LOG_LEVEL_WARNING_SPECIFIER "WARNING "
#define LOG_LEVEL_INFO_SPECIFIER "INFO "
#define LOG_LEVEL_DEBUG_SPECIFIER "DEBUG "
/**
 * Logging output options
 * 
 */
#define LOG_OUTPUT_SERIAL_DIRECT 0        /*Logging events are directly printed over serial interface when they occure*/
#define LOG_OUTPUT_SERIAL_BEGIN 1         /*Logging events are stored in the SPIFFS and printed over the serial interface at the start of the programm*/
#define LOG_OUTPUT_SERIAL_DIRECT_BEGIN 2  /*Comibination of LOG_OUTPUT_SERIAL_DIRECT and LOG_OUTPUT_SERIAL_BEGIN*/
#define LOG_OUTPUT_OFF 3                  /*Not output at all*/

class EspLogger
{
private:
  static EspLogger esp_logger_instance;
  EspSpiffs spiffs;
  EspNTP* esp_ntp;
  uint8_t log_level_ = LOG_LEVEL_INFO;
  uint8_t log_output_level_ = LOG_OUTPUT_OFF;
  uint8_t actual_log_file_ = 0;
  uint8_t row_cnt_ = 0;
  char log_message_buffer_[100];
  char* log_files_[3] = {LOG_FILE1, LOG_FILE2, LOG_FILE3};

    char* time;



public:
  static EspLogger* getInstance()
  {
    return &esp_logger_instance;
  }
  void logBegin(uint8_t log_level, uint8_t log_output_level);
  void logPrint(char* message);
  void logBuildMessage(char* specifier, char* message);

  void logFatal(char* message);
  void logError(char* message);
  void logWarning(char* message);
  void logInfo(char* message);
  void logDebug(char* message);
  
};

#endif