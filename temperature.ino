#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11     //DHT 11

DHT dht(DHTPIN, DHTTYPE);
 
// Connect pin 1 (on the left of the sensor) to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1 to 3.3V instead of 5V
// Connect pin 2 of the sensor to whatever your DHTPIN is (here 2).
// Connect pin 3 (on the right side of the sensor) to GROUNF

void setup(){
  Serial.begin(9600);
  Serial.println(F("DHT11 test!"));

  dht.begin();
}

void setup(){
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 millieseconds!
  float h = dht.readHumidity();
  // Read temperature as Celcius (the default)
  float t = dht.readTemperature();
  // Read temperaure as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperaure(true);

  // Check if any read failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)){
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celcius (isFahrenheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F(" Humidity: "));
  Serial.print(h);
  Serial.print(F("% Temperature: "));
  Serial.print(t);
  Serial.print(F("C "));
  Serial.print(f);
  Serial.print(F("F Heat index: "));
  Serial.print(hic);
  Serial.print(F("C "));
  Serial.print(hif);
  Serial.println(F("F"));
}