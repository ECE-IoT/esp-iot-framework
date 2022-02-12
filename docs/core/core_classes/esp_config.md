# Configuration

## Purpose

The aim of the implemented configuration is to write settings like wifi name and password to a separate configuration file instead of hard coding them in the source code. This gives the user the advantage of being able to change settings without having to change or re-flash the source code. 

Actually the following settings are implemented into the config.

- wifi ssid
- wifi password
- aws url
- aws port
- mqtt subscribe topic
- mqtt publish topic
- device id
- device position
- logger level
- logger output level

## Implementation

### Create Config file

To create the configuration file the python script ``generate_config.py`` is used. This script must be called from a command line, and the settings are then entered from the command line as well. Then a file called ``config_file.json`` is created automatically and stored in a directory with the name data.

The created configuration file is of the type [json](https://www.w3schools.com/js/js_json_intro.asp). This format is commonly used in IoT applications for data exchange. In a json file the data is stored as text in a ordered way. This makes it easy to create, edit and read these files.

### Upload Config

On the ESP device the configuration file is stored in the [SPIFFS](esp_spiffs.md) file system together with the certificates for the ssl connection.

To upload the configuration we suggest to use PlatformIO but you are also free to use a other option like the [Arduino-IDE](https://randomnerdtutorials.com/install-esp32-filesystem-uploader-arduino-ide/).

The upload process is described [here](esp_spiffs.md).


### EspConfig Class

The Esp_Config class is used on the ESP to read the configuration file from SPIFFS and to make the its contents available through ``getFkt()`` functions.

The class is implemented as singleton. Therefore the normal way to get an object of the class is to call ``getInstance()`` and then a pointer to the object will be returned.

To read the config file you have to call only once the ``readConfig()`` function of the ``EspConfig`` object.

!!! Attention

    It is important to call ``readConfig()`` at the beginning in Arduino's ``Setup()`` because other functionality like [``EspConnectionHandler``](esp_connection_handler.md) use the class in there implementations. 

This class uses the class [``Esp_Spiffs``](esp_spiffs.md) to read the SPIFFS and the library [``ArduinoJson.h``](https://github.com/bblanchon/ArduinoJson) to parse the json file.