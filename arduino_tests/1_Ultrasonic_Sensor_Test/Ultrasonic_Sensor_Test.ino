/*
  Ultrasonic Sensor (HC-SR04) Test
  Description: Measures distance and prints it to the Serial Monitor.
  
  Connections:
  - VCC to 5V on Arduino
  - GND to GND on Arduino
  - Trig pin to Arduino Pin 9
  - Echo pin to Arduino Pin 10
*/

const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.println("Ultrasonic Sensor Test Initialized");
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}
