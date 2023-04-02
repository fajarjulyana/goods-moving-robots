const int trigPin = 9;

const int echoPin = 10;

const int motorPin1 = 5;

const int motorPin2 = 6;

const int enablePin = 11;

long duration, distance;

void setup() {

  pinMode(trigPin, OUTPUT);

  pinMode(echoPin, INPUT);

  pinMode(motorPin1, OUTPUT);

  pinMode(motorPin2, OUTPUT);

  pinMode(enablePin, OUTPUT);

  Serial.begin(9600);

}

void loop() {

  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration / 2) / 29.1;

  Serial.print(distance);

  Serial.println(" cm");

  if (distance < 10) {

    digitalWrite(motorPin1, LOW);

    digitalWrite(motorPin2, LOW);

  } else {

    digitalWrite(motorPin1, HIGH);

    digitalWrite(motorPin2, LOW);

    analogWrite(enablePin, 200);

  }

}
