# SCD30

## Type

- Temperature
- Humidity
- CO2 

## Specs

- NDIR CO2 sensor technology
- Integrated temperature and humidity sensor
- Best performance-to-price ratio
- Dual-channel detection for superior stability
- Small form factor: 35 mm x 23 mm x 7 mm
- Measurement range: 400 ppm – 10.000 ppm
- Accuracy: ±(30 ppm + 3%)
- Current consumption: 19 mA @ 1 meas. per 2 s.
- Fully calibrated and linearized
- Digital interface UART or I2C

## Description

The SCD-30 is an NDIR sensor, which is a 'true' CO2 sensor, that will tell you the CO2 PPM (parts-per-million) composition of ambient air. Unlike the SGP30, this sensor isn't approximating it from VOC gas concentration - it really is measuring the CO2 concentration! That means its a lot bigger and more expensive, but it is the real thing. Perfect for environmental sensing, scientific experiments, air quality and ventilation studies and more.

Data is read over I2C, so it works very nicely with just about any microcontroller or microcomputer. We've written both Arduino and Python/CircuitPython code so you can get started in a jiffy. Another nice element to this sensor is it comes with an SHT31 temperature and humidity sensor already built in. The sensor is used to compensate the NDIR CO2 sensor, but its also readable so you get full environmental data.

We’ve of course broken out all the pins to standard headers and added a 3.3V voltage regulator and level shifting so allow you to use it with either 3.3V or 5V systems such as the Raspberry Pi, or Metro M4 or Arduino Uno.

## Source
[Adafruit](https://learn.adafruit.com/adafruit-scd30)
