#include <string>

class Sensor
{
  public:
    int lower_value;
    int upper_value;
    float value;
    std::string unit;
    std::string sensor_type;
    std::string mqtt_topic;

    void setValue();
    void updateValue();
    void setupSensor();

    Sensor(int, int, float, std::string, std::string, std::string)
};

