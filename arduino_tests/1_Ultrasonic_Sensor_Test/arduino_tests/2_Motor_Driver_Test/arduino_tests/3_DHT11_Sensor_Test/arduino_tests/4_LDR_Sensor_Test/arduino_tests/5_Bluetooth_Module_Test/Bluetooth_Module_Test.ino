/*
  Bluetooth Module (HC-05/HC-06) Test
  Description: Receives commands via a Bluetooth terminal app to control the onboard LED.

  Connections:
  - HC-05 VCC to 5V on Arduino
  - HC-05 GND to GND on Arduino
  - HC-05 TXD to Arduino Pin 10 (Software RX)
  - HC-05 RXD to Arduino Pin 11 (Software TX)
*/

#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11); // RX, TX

char command;

void setup() {
  Serial.begin(9600);
  Serial.println("Bluetooth Command Test Initialized");
  
  bluetooth.begin(9600);
  
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (bluetooth.available() > 0) {
    command = bluetooth.read();

    Serial.print("Received: ");
    Serial.println(command);

    if (command == '1') {
      digitalWrite(LED_BUILTIN, HIGH);
      bluetooth.println("LED is ON");
    } else if (command == '0') {
      digitalWrite(LED_BUILTIN, LOW);
      bluetooth.println("LED is OFF");
    }
  }
}
