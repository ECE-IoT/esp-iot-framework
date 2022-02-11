## Purpose

The Connection Hanlder is used to manage the Wifi connection and the TLS MQTT connection to the AWS broker.

## Implementation

### Setup

In the ``Setup()`` the initialization of ``EspMqtt``, ``EspNtp``and ``EspWifi`` is done.

To do this, the necessary configuration information is read from the configuration file with the help of ``EspConfig``. The information is used to establish a first Wifi connection, to pass the configuration to MQTT and also to set the time zone of the ntp.

### Loop

Now, this is where the actual main function of the connection handler comes into play.

To automatically handle connecting and reconnecting to Wifi and the mqtt broker following statemachine is used.

States:

1. ``CONNECT_WIFI``

    Initial state. Here the state machine connects the device to the wifi and changes to ``CONNECT_MQTT`` when the Wifi is connected.

2. ``CONNECT_MQTT``

    Checks if Wifi is connected and switches to ``CONNECT_WIFI`` if neccessary. Establishes MQTT connection and sends an init message to the aws broker. When the connection is established, the statemachine switches to ``CONNECTED``.

3. ``CONNECTED``

    In this state the Wifi and MQTT connection is constantly checked and in case of a connection loss the Stemachine switches either to ``CONNECT_MQTT`` or to ``CONNECT_WIFI``.

When the state machine is called in code, it returns the current state. If the returned state is ``CONNECTED``, then this signals to the [scheduler] (insert TODO link to sceduler doku) that everything is ready and it can start sending data.

The statemachine is designed to be non blocking. That menas for example during the reconnecting to the Wifi instead of waiting in the statemachine until Wifi is connected the programm calls the reconnecting method and then exits the statemachine.

That assures that the ``Loop()`` is executed continiusly and that enables the user to use a Wachtdog or put your own code after the Sceduler into the ``loop()`` which will then be executed continiously.

## EspConenctionHandler Class