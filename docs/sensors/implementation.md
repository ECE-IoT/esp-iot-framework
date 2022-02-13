# Implementation

The functionality of the sensors within the framework is defined by the following 3 independently acting functions.

## setup

In the setup function, which is called once when the application is started, the framework initializes the respective sensor.
```cpp
  void EspSensor.setup(){};
```
When implementing a new sensor, any initialization of the sensor in the sample code must be integrated into this function. 

## setValue

The set_value function is called cyclically with the help of the scheduler and determines the current measured value and stores it in the specified variable.
```cpp
  void EspSensor.setValue(float value)
```
When implementing a new sensor, the measured value for each measurement determined by the sample code or function must be stored directly in the variable provided for the physical sensor. 

## update

With the update function, which is also called cyclically with the help of the scheduler, the variables containing the data of the sensor including the measurement data are uploaded to the MQTT broker.
```cpp
  void EspSensor.update()
```
When implementing a new sensor, as long as the sensor object was created correctly, no changes need to be made in the update function. Only the physical sensors must be selected.

## Implementing a new Sensor
If a sensor should be added that is not yet integrated in the framework, this is done by first defining the new sensor.
It is recommended to use the example code of the manufacturer for the respective platform.

The type of sensor is defined based on the physical quantities that the sensor measures.
When creating the subclass of the sensor, these quantities must be defined by their own sensor objects within the subclass.
If libraries provided by the manufacturer are required, these must be included.

The functions which provide the use of the sensor should always be globally related to the respective sensor to be integrated. 
For example, with the DHT22, which measures air temperature and humidity, the measurement of both sensor objects is started with a call to setValue.
