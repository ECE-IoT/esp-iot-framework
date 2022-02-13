# LPS25

## Type

- Temperature
- Pressure

## Specs

- 3,3 to 5V power and I/O
- Range: 260-1260 hPa
- Accuracy: 0.2 hPa after calibration
            +-1 hPa before calibration
- maximum Sampling Rate: 25Hz
- Body size: 25mm X 25mm X 7,6mm
- Form Faktor: STEMMA QT / Qwiic
- Current Consumption: High resolution mode: 25µA
                      low power mode: 4µA
- Communication Interface: I2C, SPI

## Description

This absolute pressure sensor, ST LPS25HB can quickly and easily measure this air pressure, useful when you want to know about the weather (are we in a low pressure or high pressure system?) or to determine altitude, as the air thins out the higher we get above sea level. For example, at sea level, the official pressure level is 1013.25 hPa. You can use this sensor to measure the current pressure where you are right now, to compare.

The LPS25 has a wide measurement range of 260-1260 hPa with 24-bit pressure data measurements that can be read up to 25 times a second (Hz), you can be confident that you always have an up to date and precise measurement. It's pretty dang accurate too, with the ability to measure within 0.2 hPa after calibration (± 1 hPa before calibration).

These days, helpful little sensors like the LPS25 are often quite little and tend to come in surface-mount packages that make them tricky to use with breadboards. With that in mind, we've taken the LPS25 and put it on a breakout board with level shifting circuitry and a voltage regulator. This means that not only can you use it with a breadboard, but you can use it with a wide range of devices that have either a 3.3V logic level, like a Raspberry Pi or CircuitPython compatible Metro M4 Express, or with a 5V logic level device like a Metro 328 or Arduino Uno.

## Source
[Adafruit](https://www.adafruit.com/product/4530)
