#!/usr/bin/env python3
import os.path
import json

dir_path = os.path.normpath(os.path.join(__file__, '..' , '..' , 'data'))
file_path = os.path.join(dir_path, 'config_file.json')

## get user input-----------------------------------------
ssid = input("Enter wifi ssid: ")
pswd = input("Enter wifi password: ")
name = input("Enter device name: ")
device_position = input("Enter device position: ")
pub_topic = input("Enter publish topic: ")
sub_topic = input("Enter subscribe topic: ")
logger_level = input("""
LOG_LEVEL_OFF       0   no logging
LOG_LEVEL_FATAL     1   Designates very severe error events that will presumably lead the application to abort
LOG_LEVEL_ERROR     2   Designates error events that might still allow the application to continue running
LOG_LEVEL_WARNING   3   Designates potentially harmful situations
LOG_LEVEL_INFO      4   Designates informational messages that highlight the progress of the application at coarse-grained level.
LOG_LEVEL_DEBUG     5   Designates fine-grained informational events that are most useful to debug an application.

Enter logger level number: """)
logger_output = input(""" 
LOG_OUTPUT_SERIAL_DIRECT        0  Logging events are directly printed over serial interface when they occure
LOG_OUTPUT_SERIAL_BEGIN         1  Logging events are stored in the SPIFFS and printed over the serial interface at the start of the programm
LOG_OUTPUT_SERIAL_DIRECT_BEGIN  2  Comibination of LOG_OUTPUT_SERIAL_DIRECT and LOG_OUTPUT_SERIAL_BEGIN
LOG_OUTPUT_OFF                  3  Not output at all

Enter logger output number: """)




## create json--------------------------------------------
json_dict = {
  "ssid":ssid,
  "password":pswd,
  "aws_url":"aq60dkt3q20bd-ats.iot.eu-central-1.amazonaws.com",
  "aws_port":8883, 
  "mqtt_pub_topic":pub_topic,
  "mqtt_sub_topic":sub_topic,
  "device_id":name,
  "device_position":device_position,
  "logger_level":int(logger_level),
  "logger_output":int(logger_output)
}

file_data = json.dumps(json_dict, indent=0)

## write to file------------------------------------------
if not os.path.exists(dir_path):
  os.makedirs(dir_path)

f = open(file_path, "w")
f.write(file_data)
f.close()