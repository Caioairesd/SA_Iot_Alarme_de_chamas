#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

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

lcd.init();
lcd.backlight();
lcd.setCursor(0,0);
lcd.print("Sistema Fogo");

  
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
