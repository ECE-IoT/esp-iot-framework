# Scheduler

## Purpose

In order to get `sensor` values with a constant period the ESP needs to send them scheduled to the `MQTT broker`. To achieve this, the `iotScheduler` function can be used. It takes a certain number of `milliseconds` as an input. In addition a callback function can be registered where any functionality for gathering and sending date takes place. 

## Usage

The `iotScheduler` is a non-blocking type of scheduler. It uses the `millis` function to create the necessary period. A typical usage within the `main` loop could look like the following example:

```cpp

void callBack();

void loop()
{
  iotScheduler(PERIOD, callBack);
}

void callBack()
{
  /**
   * Do any schedule logic here
   */
}
```