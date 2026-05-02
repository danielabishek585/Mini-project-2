const int sensorPins[] = {6, 7, 8, 11, 12}; 
const int motorPin1 = 2;
const int motorPin2 = 3;
const int motorPin3 = 4;
const int motorPin4 = 5;
const int enableA = 9;
const int enableB = 10;
const int trigPin = A1;
const int echoPin = A2;
float Kp = 1.0; 
float Ki = 0.0; 
float Kd = 0.5; 
int sensorValues[5];
float lastError = 0.0;
float integral = 0.0;
void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(sensorPins[i], INPUT);
  }
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  analogWrite(enableA, 255); 
  analogWrite(enableB, 255); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
void loop() {
  for (int i = 0; i < 5; i++) {
    sensorValues[i] = digitalRead(sensorPins[i]);
  }
  float error = 0.0;
  if (sensorValues[0] == LOW) error = -2;
  if (sensorValues[1] == LOW) error = -1;
  if (sensorValues[2] == LOW) error = 0;
  if (sensorValues[3] == LOW) error = 1;
  if (sensorValues[4] == LOW) error = 2;
  integral += error;
  float derivative = error - lastError;
  float controlSignal = Kp * error + Ki * integral + Kd * derivative;
  lastError = error;
  if (isObstacleDetected()) {
    stopMotors();
  } else {
    if (controlSignal > 0) {
      turnRight();
    } else if (controlSignal < 0) {
      turnLeft();
    } else {
      moveForward();
    }
  }
  for (int i = 0; i < 5; i++) {
    Serial.print(sensorValues[i]);
    Serial.print(" ");
  }
  Serial.println();
  Serial.print("Control Signal: ");
  Serial.println(controlSignal);
}
bool isObstacleDetected() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;
  return distance < 15;
}
void moveForward() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}
void turnLeft() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}
void turnRight() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}
void stopMotors() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}