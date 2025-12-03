const int fireSensorPin = 7;
const int ledPin = 8;
const int buzzerPin = 13;

void setup() {
pinMode(fireSensorPin, INPUT_PULLUP);
pinMode(ledPin, OUTPUT);
pinMode(buzzerPin, OUTPUT);
}

void loop() {
int fireDetected = digitalRead(fireSensorPin);

if (fireDetected == LOW) {
digitalWrite(ledPin, HIGH);
tone(buzzerPin, 1000);
} else {
digitalWrite(ledPin, LOW);
noTone(buzzerPin);
}
}
