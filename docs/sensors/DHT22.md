# DHT22

## Type

- Temperature
- Humidity

## Specs

- Low cost
- 3 to 5V power and I/O
- 2.5mA max current use during conversion (while requesting data)
- Good for 0-100% humidity readings with 2-5% accuracy
- Good for -40 to 80°C temperature readings ±0.5°C accuracy
- No more than 0.5 Hz sampling rate (once every 2 seconds)
- Body size 27mm x 59mm x 13.5mm (1.05" x 2.32" x 0.53")
- 3 wires 23cm long (9")
- 27mm wide x 58.75mm tall x 13.30mm deep

## Description

The AM2302 is a wired version of the DHT22, in a large plastic body. It is a basic, low-cost digital temperature and humidity sensor. It uses a capacitive humidity sensor and a thermistor to measure the surrounding air and spits out a digital signal on the data pin (no analog input pins needed). It's fairly simple to use but requires careful timing to grab data. The only real downside of this sensor is you can only get new data from it once every 2 seconds, so when using our library, sensor readings can be up to 2 seconds old.

Simply connect the red 3-5V power, the yellow wire to your data input pin, and the black wire to ground. Although it uses a single wire to send data it is not Dallas One Wire compatible! If you want multiple sensors, each one must have its own data pin.

## Source
[Adafruit](https://www.adafruit.com/product/393)
