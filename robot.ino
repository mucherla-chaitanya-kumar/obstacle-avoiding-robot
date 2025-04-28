#define trigPin 9
#define echoPin 10
#define motorLeftForward 2
#define motorLeftBackward 3
#define motorRightForward 4
#define motorRightBackward 5

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(motorLeftForward, OUTPUT);
  pinMode(motorLeftBackward, OUTPUT);
  pinMode(motorRightForward, OUTPUT);
  pinMode(motorRightBackward, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Obstacle Avoiding Robot Initialized");
}

void loop() {
  long duration, distance;
  
  // Send Ultrasonic Pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read Echo
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Distance in cm
  
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 15) { // Obstacle detected within 15 cm
    stopMoving();
    delay(500);
    moveBackward();
    delay(500);
    turnRight();
    delay(700);
  } else {
    moveForward();
  }
}

void moveForward() {
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightBackward, LOW);
}

void moveBackward() {
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftBackward, HIGH);
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightBackward, HIGH);
}

void turnRight() {
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightBackward, HIGH);
}

void stopMoving() {
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightBackward, LOW);
}
