const int fireSensorPin = 7;
const int resetButtonPin = 6;
const int ledPin = 8;
const int buzzerPin = 13;

void setup() {
  pinMode(fireSensorPin, INPUT_PULLUP);
  pinMode(resetButtonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

}
