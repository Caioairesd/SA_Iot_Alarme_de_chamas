const int fireSensorPin = 7;
const int resetButtonPin = 6;
const int ledPin = 8;
const int buzzerPin = 13;

bool alarmActive = false;

void setup() {
pinMode(fireSensorPin, INPUT_PULLUP);
pinMode(resetButtonPin, INPUT_PULLUP);
pinMode(ledPin, OUTPUT);
pinMode(buzzerPin, OUTPUT);
}

void loop() {
int fireDetected = digitalRead(fireSensorPin);
int resetPressed = digitalRead(resetButtonPin);

if (fireDetected == LOW) {
alarmActive = true;
}

if (resetPressed == LOW) {
alarmActive = false;
}

if (alarmActive) {
digitalWrite(ledPin, HIGH);
tone(buzzerPin, 1500);
} else {
digitalWrite(ledPin, LOW);
noTone(buzzerPin);
}
}
