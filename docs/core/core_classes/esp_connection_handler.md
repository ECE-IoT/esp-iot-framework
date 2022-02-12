## Purpose

The aim of the connection handler is to manage the Wifi connection and the TLS MQTT connection to the AWS broker.

## Implementation

### Setup

In the Arduino's ``setup()`` the initialization of [``EspMQTT``](esp_mqtt.md), [``EspNTP``](esp_ntp.md) and [``EspWifi``](esp_wifi.md) is done.

To do this, the necessary configuration information is read from the configuration file with the help of ``EspConfig``. The information is used to establish a first Wifi connection, to pass the configuration to MQTT and also to set the time zone of the ntp.

### Loop

Now, this is where the actual main function of the connection handler comes into play.

To automatically handle connecting and reconnecting to Wifi and the mqtt broker following state machine is used.

**States**:

1. ``CONNECT_WIFI``

    Initial state. Here the state machine connects the device to the wifi and changes to ``CONNECT_MQTT`` when the Wifi is connected.

2. ``CONNECT_MQTT``

    Checks if Wifi is connected and switches to ``CONNECT_WIFI`` if necessary. Establishes MQTT connection and sends an init message to the aws broker. When the connection is established, the state machine switches to ``CONNECTED``.

3. ``CONNECTED``

    In this state the Wifi and MQTT connection is constantly checked and in case of a connection loss the State machine switches either to ``CONNECT_MQTT`` or to ``CONNECT_WIFI``.

When the state machine is called in code, it returns the current state. If the returned state is ``CONNECTED``, then this signals to the [scheduler] (insert TODO link to scheduler doku) that everything is ready and it can start sending data.

The state machine is designed not to block the program during execution. For example, if reconnecting to the wifi, the "reconnect" function is called and then the state machine is exited instead of waiting in the state machine until the wifi is connected.

This ensures that the ``loop()`` is executed continuously and allows the user to use a watchdog or put custom code after the scheduler in the ``loop()`` which is then executed continuously.

## EspConnectionHandler Class

The class implements the functionality described before.

The ``setup()`` function of the class is called in Arduino's ``setup()`` and it handles all the setup functionality described above. 

!!! Attention

    We assume that you use the [``EspConfig``](esp_config.md) in other places in your program and therefore it is important that you call the ``readConfig()`` function in ``setup()`` before calling ``EspConnectionHandler.setup()``.

The ``runHandler()`` function of the class implements the state machine. This function is called in Arduino's ``loop()`` and it returns the actual state. The state is of the type ``enum connection_states``.

The class uses the [``EspMQTT``](esp_mqtt.md), [``EspNTP``](esp_ntp.md), [``EspConfig``](esp_config.md), [``EspJson``](esp_json.md) and [``EspWifi``](esp_wifi.md) classes of the core.