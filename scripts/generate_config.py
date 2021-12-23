#!/usr/bin/env python3
import os.path
import json

dir_path = os.path.normpath(os.path.join(__file__, '..' , '..' , 'data'))
file_path = os.path.join(dir_path, 'config_file.json')

## get user input-----------------------------------------
ssid = input("Enter wifi ssid: ")
pswd = input("Enter wifi password: ")


## create json--------------------------------------------
json_dict = {
  "ssid":ssid,
  "password":pswd,
  "aws_url":"aq60dkt3q20bd-ats.iot.eu-central-1.amazonaws.com",
  "aws_port":8883, 
  "mqtt_topic":"esp32-d1mini-01"
}

file_data = json.dumps(json_dict, indent=0)

## write to file------------------------------------------
if not os.path.exists(dir_path):
  os.makedirs(dir_path)

f = open(file_path, "w")
f.write(file_data)
f.close()