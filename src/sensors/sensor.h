class Sensor
{
  public:
    struct value_range
    {
      float lower_value;
      float upper_value;
    };
    float sensor_value;
    char* unit;
    char* sensor_type;
    char* mqtt_topic;

    void setValue();
    void updateValue();
};