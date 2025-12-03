const int fireSensorPin = 7;
const int resetButtonPin = 6;
const int ledPin = 8;
const int buzzerPin = 13;

void setup() {
pinMode(fireSensorPin, INPUT_PULLUP);
pinMode(ledPin, OUTPUT);
}

void loop() {
int fireDetected = digitalRead(fireSensorPin);

if (fireDetected == LOW) {
digitalWrite(ledPin, HIGH);
} else {
digitalWrite(ledPin, LOW);
}
}
