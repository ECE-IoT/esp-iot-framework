# Logger

## Purpose

The purpose of the logger is to log messages with different log levels such as info, debug in a file on the SPIFFS and print the information either at the beginning of the program via the serial monitor or directly during the program, depending on the configuration

The aim of these is to inform the user about the device status and to simplify and speed up debugging.

## Implementation

The configuration described below is passed to the program via the [``config file``](esp_config.md).

### Log levels

For the logging one of the following log levels can be selected: 

1. ``LOG_LEVEL_OFF`` 

    No logging.

2. ``LOG_LEVEL_FATAL``

    Designates very severe error events that will presumably lead the application to abort.

3. ``LOG_LEVEL_ERROR``

    Designates error events that might still allow the application to continue running.

4. ``LOG_LEVEL_WARNING`` 

    Designates potentially harmful situations.

5. ``LOG_LEVEL_INFO``

    Designates informational messages that highlight the progress of the application at coarse-grained level.

6. ``LOG_LEVEL_DEBUG``

    Designates fine-grained informational events that are most useful to debug an application.

!!! note
    For example, if INFO is selected, WARNING, ERROR and FATAL messages will still be logged, but DEBUG messages will not. This is how the levels work.

### Logging

For the output one of the following options can be selected: 

1. ``LOG_OUTPUT_SERIAL_DIRECT``

    Logging events are directly printed over serial interface when they occur.

2. ``LOG_OUTPUT_SERIAL_BEGIN``  

    Logging events are stored in the SPIFFS and printed over the serial interface at the start of the program.

3. ``LOG_OUTPUT_SERIAL_DIRECT_BEGIN``

    Combination of ``LOG_OUTPUT_SERIAL_DIRECT`` and ``LOG_OUTPUT_SERIAL_BEGIN``.

4. ``LOG_OUTPUT_OFF``     

    Not output at all.

### Log file storage

The logged information is stored in three files on the SPIFFS. Each has a length of 100 lines. This is determined by the ``LOG_FILE_MAX_ROWS`` definition. This limits the logging to a total of 300 messages with the purpose of preventing Flash from becoming completely full if the program runs for a very long time. When all three files are full, the logger starts again with the first file and overwrites it.

## EspLogger

These class implements the functionality described above.

The class is implemented as singleton. Therefore the normal way to get an object of the class is to call ``getInstance()`` and then a pointer to the object will be returned.

By calling ``logBegin(log_level, log_output_level)`` the logger is initialized and the logged messages from the last program call is depending on the log_output_level printed to the serial monitor. The parameters ``log_level`` and ``log_output_level`` are stored in the configuration file and can be accessed using the [``Esp_Config``](esp_config.md) class.

In your code you can call on of the following functions to log a message with a specific log level.

- ``logFatal(message)``;
- ``logError(message)``;
- ``logWarning(message)``;
- ``logInfo(message)``;
- ``logDebug(message)``;

!!! note

    The logger automatically adds an appropriate label and timestamp to your message. This means that you only have to worry about the content of the message and the logger takes care of the rest.

The class uses the [``EspSpiffs``](esp_spiffs.md) to access SPIFFS and the [``Ntp``](esp_ntp.md) class to get the current time.
