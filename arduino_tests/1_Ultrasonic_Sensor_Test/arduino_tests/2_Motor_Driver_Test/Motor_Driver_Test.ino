/*
  DC Motors & L298N Driver Test
  Description: Tests robot movement by cycling through forward, stop, and backward.

  Connections:
  - L298N ENA to Arduino Pin 5 (PWM)
  - L298N IN1 to Arduino Pin 7
  - L298N IN2 to Arduino Pin 8
  - L298N IN3 to Arduino Pin 11
  - L298N IN4 to Arduino Pin 12
  - L298N ENB to Arduino Pin 6 (PWM)
  - Connect motors to OUT1/OUT2 and OUT3/OUT4 terminals.
  - Connect battery pack to 12V and GND terminals of the L298N.
*/

const int enA = 5;
const int in1 = 7;
const int in2 = 8;
const int enB = 6;
const int in3 = 11;
const int in4 = 12;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Serial.begin(9600);
  Serial.println("L298N Motor Driver Test Initialized");
}

void loop() {
  Serial.println("Moving Forward");
  analogWrite(enA, 200); 
  analogWrite(enB, 200);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(2000);

  Serial.println("Stopping");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(1000);

  Serial.println("Moving Backward");
  analogWrite(enA, 200);
  analogWrite(enB, 200);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(2000);

  Serial.println("Stopping");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(1000);
}
