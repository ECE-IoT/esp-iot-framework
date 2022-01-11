#ifndef VERT_PROT_SENSOR
#define VERT_PROT_SENSOR

#include <DHT.h>
#include "Arduino.h"
#include "sensor.h"

class DHT_Sensor : public EspComponent <void>
{
private:
  DHT dht22;

  Sensor temperature;
  temperature.value_range->lower_value(-20);
  temperature.value_range->upper_value(80);
  temperature.value(value);
  temperature.unit("C");
  temperature.sensor_type("temperature");
  temperature.mqtt_topic("/temp";)

  Sensor humidity;
  humidity.value_range->lower_value(0);
  humidity.value_range->upper_value(100);
  humidity.value(value);
  humidity.unit("%");
  humidity.sensor_type("humidity");
  humidity.mqtt_topic("/hum");

public:
  DHT_Sensor(char type, char pin);
  void setupSensor();
  void updateValue();
  void setValue();
};

#endif