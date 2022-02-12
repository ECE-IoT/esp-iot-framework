# SPIFFS

## Description

[SPIFFS](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/storage/spiffs.html) (Serial Peripheral Interface Flash File System) is a simple file system which is located on the ESP flash storage. The advantage of the file system is that we can change the configuration and tls certificate files independently of the source code.  

## Upload to SPIFFS

To upload the SPIFFS we suggest to use PlatformIO but you are also free to use a other option like the [Arduino-IDE](https://randomnerdtutorials.com/install-esp32-filesystem-uploader-arduino-ide/).

**How To upload the SPIFFS with PlatformIO**

1. Connect your ESP to your computer using a USB cable.

2. In VS Code, open the PlatformIO extension on the left side and then open the esp device folder under ``PROJECT TASKS``. You should then see a view similar to the following image. 
![folder image](.//..//../assets/upload_spiffs.png)

3. Click on ``Build Filesystem Image`` and wait until the task finishes. This is indicated when ``SUCCESS`` is printed at the terminal. What happens is that the content in the top directory data is used to build a spiffs image.

4. Click on ``Upload Filesystem Image``. Now the previously build image is uploaded to the flash storage of the connected ESP.

## EspSpiffs class

The ``EspSpiffs`` class is used to read the SPIFFS on the ESP in a structured way. The class is used by the other classes ``Keys`` ,``Esp_Config`` and ``Esp_Logger``.

This class uses the library ``SPIFFS.h`` from Espressif. It is described [here](https://arduino-esp8266.readthedocs.io/en/latest/filesystem.html).