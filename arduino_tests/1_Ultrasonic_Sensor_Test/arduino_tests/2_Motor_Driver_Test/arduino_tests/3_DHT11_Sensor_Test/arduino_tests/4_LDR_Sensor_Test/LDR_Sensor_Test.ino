/*
  LDR (Light Dependent Resistor) Test
  Description: Reads the ambient light level and prints its raw analog value.
  
  Connections:
  - One leg of LDR to 5V.
  - The other leg of LDR to Arduino Pin A0.
  - Connect a 10k Ohm resistor from Pin A0 to GND.
*/

const int ldrPin = A0;

void setup() {
  Serial.begin(9600);
  Serial.println("LDR Light Sensor Test Initialized");
}

void loop() {
  int ldrValue = analogRead(ldrPin);

  Serial.print("LDR Raw Value: ");
  Serial.println(ldrValue);

  delay(500);
}
