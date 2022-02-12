# EspWifi Class

## Purpose

The aim of this class is to bundle the functionality for structured access to the WLAN connection in one class. This ensures that the WLAN connection is always accessed in the same way which helps to avoid errors.

The class is used in the ``connection handler``.

The class uses the [``WiFi.h``](https://github.com/espressif/arduino-esp32/tree/master/libraries/WiFi) library from the Arduino ESP Core.

## How to use?

For a initial wifi connection the function ``beginWifi(ssid, password)`` has to be called. The function passes the parameters ``ssid`` and ``password``. These parameters are stored in the configuration file and can be accessed using the ``Esp_Config`` class.The current WLAN status can be checked with ``statusWifi()`` and the connection can be re-established with ``reconnectWifi()``.

