# Sensor

## Purpose 

The functionality of the [Sensors](../../sensors/introduction.md) rely on two main components which are implemented in the `core` functions: 

* `EspSensor` super-class
* `Physical Sensors` which implement the `EspSensor` and form the basis for the sensor modules by defining the physically measurable quantity

## `EspSensor` super-class

### Functionality 

The `EspSensor` class exposes two methods which are later implemented by the `physical sensor` classes. 

---

```cpp
void setValue(float value)
```
This method takes an `float` as the input and saves the value in a `private` member variable. In addition the `timestamp` at the moment the method is called gets captured in order to have an accurate period measurement.

---

```cpp
void updateMQTT()
```

This method is used for sending the captured values through `MQTT` to [AWS](https://ece-iot.github.io/aws-iot-framework/aws/cli/configuration-basics/).

---

Both functions are separated in order to prevent timing problems due to a delay when sending Data to AWS. So all sensor values are read first, then they sent over `MQTT`. 

## `Physical Sensors`

The following physical entities are already implemented:

* [Temperature](https://github.com/ECE-IoT/esp-iot-framework/blob/master/src/core/physical_sensors/temperature.h)
* [Humidity](https://github.com/ECE-IoT/esp-iot-framework/blob/master/src/core/physical_sensors/humidity.h)
* [Barometric pressure](https://github.com/ECE-IoT/esp-iot-framework/blob/master/src/core/physical_sensors/pressure.h)
* [Illuminance](https://github.com/ECE-IoT/esp-iot-framework/blob/master/src/core/physical_sensors/pressure.h)
* [Gas concentration](https://github.com/ECE-IoT/esp-iot-framework/blob/master/src/core/physical_sensors/gas_concentration.h)

### Functionality 

All `physical sensor` implement the `EspSensor` as their super-class. The idea behind a structure like this is to adapt the sub-class in a manner that there is a class for every physical entity. Later, an object of the specific physical sensor class (e.g. 'Temperature') can be used to set the current measured value.

This standardizes the measurement of a physical quantity and facilitates a later analysis of the acquired data of a type.

### Adding a physical sensor

If there is the need for a new physical sensor, comply to the form of the other implementations. The following `Pre processors` need to be adapted:

```cpp
#define UNIT        "new_physical_unit"
#define SENSOR_TYPE "sensor_type"
#define MQTT_TOPIC  "/sensor_type"
```