#include "SCD30.h"

void EspSCD30::setup()
{
  scd30             = new Adafruit_SCD30;
  this->temperature = new EspTemperatureSensor(-50, 100, "4");
  this->humidity    = new EspHumiditySensor(0, 100, "4");
  this->co2         = new EspGasSensor(0, 1000000, "4");
  scd30->begin();
}

void EspSCD30::setValue()
{
  scd30->read();

  temperature->setValue(scd30->temperature);
  humidity->setValue(scd30->relative_humidity);
  co2->setValue(scd30->CO2);
}

void EspSCD30::update()
{
  temperature->updateMQTT();
  humidity->updateMQTT();
  co2->updateMQTT();
}

//example code
// Basic demo for readings from Adafruit SCD30
// #include <Adafruit_SCD30.h>

// Adafruit_SCD30  scd30;


// void setup(void) {
//   Serial.begin(115200);
//   while (!Serial) delay(10);     // will pause Zero, Leonardo, etc until serial console opens

//   Serial.println("Adafruit SCD30 test!");

//   // Try to initialize!
//   if (!scd30.begin()) {
//     Serial.println("Failed to find SCD30 chip");
//     while (1) { delay(10); }
//   }
//   Serial.println("SCD30 Found!");


//   // if (!scd30.setMeasurementInterval(10)){
//   //   Serial.println("Failed to set measurement interval");
//   //   while(1){ delay(10);}
//   // }
//   Serial.print("Measurement Interval: "); 
//   Serial.print(scd30.getMeasurementInterval()); 
//   Serial.println(" seconds");
// }

// void loop() {
//   if (scd30.dataReady()){
//     Serial.println("Data available!");

//     if (!scd30.read()){ Serial.println("Error reading sensor data"); return; }

//     Serial.print("Temperature: ");
//     Serial.print(scd30.temperature);
//     Serial.println(" degrees C");
    
//     Serial.print("Relative Humidity: ");
//     Serial.print(scd30.relative_humidity);
//     Serial.println(" %");
    
//     Serial.print("CO2: ");
//     Serial.print(scd30.CO2, 3);         <<<<<<<<<<<<<<<<<<<<<-----------------------Hier!!! Laut libary gibt der 3er an Platz im Buffer an. Weis ned ob ma den brauchen.
//     Serial.println(" ppm");
//     Serial.println("");
//   } else {
//     //Serial.println("No data");
//   }

//   delay(100);
// }
