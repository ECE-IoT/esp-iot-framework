#!/usr/bin/env python3
import os.path
import json

dir_path = os.path.normpath(os.path.join(__file__, '..' , '..' , 'data'))
file_path = os.path.join(dir_path, 'config_file.json')

## get user input-----------------------------------------
ssid = input("Enter wifi ssid: ")
pswd = input("Enter wifi password: ")
name = input("Enter device name: ")
pub_topic = input("Enter publish topic: ")
sub_topic = input("Enter subscribe topic: ")


## create json--------------------------------------------
json_dict = {
  "ssid":ssid,
  "password":pswd,
  "aws_url":"aq60dkt3q20bd-ats.iot.eu-central-1.amazonaws.com",
  "aws_port":8883, 
  "mqtt_pub_topic":pub_topic,
  "mqtt_sub_topic":sub_topic,
  "device_id":name
}

file_data = json.dumps(json_dict, indent=0)

## write to file------------------------------------------
if not os.path.exists(dir_path):
  os.makedirs(dir_path)

f = open(file_path, "w")
f.write(file_data)
f.close()