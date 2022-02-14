# MQTT

## Purpose 

The `EspMqtt` class handles the `MQTT` functionality by using an extra `MQTT Framework` called [arduino-mqtt](https://github.com/256dpi/arduino-mqtt). The class `EspMqtt` acts as an interface in order to facilitate the usage of `MQTT`. Therefore the class is implemented as a singleton structure, which guarantees that there's just one MQTT instance. With just one connection to the `MQTT Broker` throughout the whole program. 

## Functionality

### Get an object

Due to the singleton structure there is just one instance of the class  throughout the whole program. In order to fetch this instance, do the following: 

* Create a new variable with the type `EspMqtt`
* Call the following method: 

```cpp
static EspMqtt* getInstance()
{
  return &esp_mqtt_instance;
}
```

### Configure the MQTT client 

The configuration / setup works on the basis of the use of a structure called `EspMqttConfig`. This `struct` consists of the following properties: 

```cpp
struct EspMqttConfig
{
  const char* server_address;
  const char* device_id;
  const char* subscribe_topic;
  const char* publish_topic;
  uint16_t port;
};
```
Thanks to the internal functionality of the **ESP IoT Framework** an `EspMqttConfig` `struct` is created by the `EspConnectionHandler` class. There every part of the configuration for `MQTT` is read out of the `config_file.json`. 

Calling the `setup()` function for the `EspConnectionHandler`, calls the `setup` function for `MQTT` and configures the `MQTT client` correctly

### Connect client to broker

In order to connect the client to the desired `MQTT broker` use the method:

```cpp
bool connect();
```

!!! note
    This is also done within the `EspConnectionHandler`

### Register client-side callback function 

To get events from a certain topic sent from the `MQTT broker` the following function works as a interface. This interface enables the user to register a `callback` function which gets called when new data on a given topic arrives.

```cpp
template <class T> void registerClient(T subscribe_callback(char* topic, char* payload));
```
The `template` is used, so the return parameter may vary depending on the desired functionality.

### Publish / Subscribe

**Publish**
This method is used by the internal `sensors` which publish their value automatically to the `MQTT broker` with an interval set by the `EspScheduler`

**Subscribe**
This method can be used to **re-configure** the subscribe topic. It does **NOT** return any data, sent from the `MQTT broker` 