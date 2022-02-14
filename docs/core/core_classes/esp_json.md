# Json

## Purpose

The `EspJson` class is used for **serialization** of sensor values into a `char*` type `json` object. Further functionality could be the **deserialization**. This is not implemented yet!

## Usage

Create a new instance of the class. Transfer all required parameters:

```cpp
char* serializeForSensor(float value, char* unit, char* senor_type, char* unique_sensor_id, uint64_t time);
```

The return value is a `char*` which can be transmitted f.e. via `mqtt`