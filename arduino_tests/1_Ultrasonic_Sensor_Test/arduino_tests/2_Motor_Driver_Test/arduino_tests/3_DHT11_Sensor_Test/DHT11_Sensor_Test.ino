/*
  DHT11 Temperature & Humidity Sensor Test
  Description: Reads temperature and humidity and prints them to the Serial Monitor.
  Required Library: "DHT sensor library" by Adafruit.

  Connections:
  - DHT11 VCC (+) to 5V on Arduino
  - DHT11 GND (-) to GND on Arduino
  - DHT11 Data to Arduino Pin 2
*/

#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 Temperature & Humidity Test Initialized");
  dht.begin();
}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");
}
