# Keys and Certificates

## Why do we need a key and certificate files?

To establish a TLS connection with device authentication the following three files are necessary:

1. Private Key (esp32-d1mini-01.private.key)
2. Device Certificate (esp32-d1mini-01.cert.crt)
3. Root Certificate (root-CA.pem)

You get these files from AWS and the process is described here. These three files are stored on the [SPIFFS](esp_spiffs.md). 

To store them in the file system you just have to put the files together with the config file into the data directory and then follow the upload process which is described [here](esp_spiffs.md). 

!!! attention
    It is important that the files have exactly the same name as seen in the brackets above.


## Keys Class

The purpose of this class is to read the three files from the file system and make them accessible by ``getFkt()`` functions. The files are read first by calling the ``begin()`` function of the class.

The class uses the [``EspSpiffs``](esp_spiffs.md) class to read from the file system.