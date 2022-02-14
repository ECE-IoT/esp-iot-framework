# NTP

## Purpose

Fetches *time* information from the local time-zone via an NTP server. 

* `char* EspNTP::getValueChar()` returns value as a string
* `uint64_t EspNTP::getValue()` returns value as UNIX integer value

The NTP class is based upon the work of [NTP](https://github.com/gmag11/ESPNtpClient.git). 