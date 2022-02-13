# Introduction

In order to use sensors for the measurement of data by means of the framework, an own concept for the processing of these data was developed.To limit the massive selection of sensors, the use was limited to 2 different types of connections. These connection types are I2C and One-Wire. Since most of the sensors available on the market can handle at least one of these connection types, the implementation of other protocols such as UART or SPI could be omitted for the time being.

Since the power supply is circuit-dependent, no consideration had to be given to the supply voltage during the development of the framework. If the adapter board developed in the project should be used, it is recommended to use sensors with a supply voltage of 5V.

The following chapters are intended to show the user which sensors are integrated in the framework by default and also to provide a brief guide to the implementation of new sensors.
