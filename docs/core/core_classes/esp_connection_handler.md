## Purpose

The aim of the connection handler is to manage the Wifi connection and the TLS MQTT connection to the AWS broker.

## Implementation

### Setup

In the ``Setup()`` the initialization of [``EspMQTT``](esp_mqtt.md), [``EspNTP``](esp_ntp.md) and [``EspWifi``](esp_wifi.md) is done.

To do this, the necessary configuration information is read from the configuration file with the help of ``EspConfig``. The information is used to establish a first Wifi connection, to pass the configuration to MQTT and also to set the time zone of the ntp.

### Loop

Now, this is where the actual main function of the connection handler comes into play.

To automatically handle connecting and reconnecting to Wifi and the mqtt broker following statemachine is used.

**States**:

1. ``CONNECT_WIFI``

    Initial state. Here the state machine connects the device to the wifi and changes to ``CONNECT_MQTT`` when the Wifi is connected.

2. ``CONNECT_MQTT``

    Checks if Wifi is connected and switches to ``CONNECT_WIFI`` if neccessary. Establishes MQTT connection and sends an init message to the aws broker. When the connection is established, the statemachine switches to ``CONNECTED``.

3. ``CONNECTED``

    In this state the Wifi and MQTT connection is constantly checked and in case of a connection loss the Stemachine switches either to ``CONNECT_MQTT`` or to ``CONNECT_WIFI``.

When the state machine is called in code, it returns the current state. If the returned state is ``CONNECTED``, then this signals to the [scheduler] (insert TODO link to sceduler doku) that everything is ready and it can start sending data.

The state machine is designed not to block the program during execution. This means, for example, that when the program reconnects to the Wifi, it calls the reconnect function and then exits the state machine instead of waiting in the state machine until the Wifi is connected.

This ensures that the ``Loop()`` is executed continuously and allows the user to use a watchdog or put custom code after the sceduler in the ``Loop()`` which is then executed continuously.

## EspConenctionHandler Class

The class implements the functionallity descrribed before.

The ``stetp()`` function of the class is called in Arduinos ``Setup()`` and it handles all the setup functionallity described above. 

!!! Attention

    We assume that you use the [``EspConfig``](esp_config.md) in other places in your program and therefore it is important that you call the ``readConfig()`` function in ``Setup()`` before calling ``EspConenctionHandler.stetp()``.

The ``runHadler()`` function of the class implements the statemachine. This function is called in Arduinos ``Loop()`` and it returns the actuall state. The state is of the type ``enum connection_states``.

The class uses the [``EspMQTT``](esp_mqtt.md), [``EspNTP``](esp_ntp.md), [``EspConfig``](esp_config.md), [``EspJson``](esp_json.md) and [``EspWifi``](esp_wifi.md) classes of the core.