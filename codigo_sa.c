#include <LiquidCrystal_I2C.h>

// Endereço do LCD (0x27 ou 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pinos
const int fireSensorPin = 7;     // Sensor de fogo
const int resetButtonPin = 6;    // Botão de reset
const int ledPin = 8;            // LED de alerta
const int buzzerPin = 13;        // Buzzer

bool alarmActive = false;
bool alarmDisplayed = false;

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  pinMode(fireSensorPin, INPUT_PULLUP);
  pinMode(resetButtonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Tela inicial
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Senai");
  lcd.setCursor(0, 1);
  lcd.print("Joinville");
}

void loop() {
  int fireDetected = digitalRead(fireSensorPin);
  int resetPressed = digitalRead(resetButtonPin);

  // ───── ATIVA ALARME ─────
  if (fireDetected == LOW && !alarmActive) {
    alarmActive = true;
    alarmDisplayed = false;
  }

  // ───── RESET DO ALARME ─────
  if (resetPressed == LOW) {
    delay(50); // debounce
    if (digitalRead(resetButtonPin) == LOW && alarmActive) {

      alarmActive = false;
      noTone(buzzerPin);
      digitalWrite(ledPin, LOW);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("LCD OK!");
      lcd.setCursor(0, 1);
      lcd.print("Reset funciona");

      delay(2000); 
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Senai");
      lcd.setCursor(0, 1);
      lcd.print("Joinville");
    }
  }

  // ───── MODO ALARME ─────
  if (alarmActive) {

    if (!alarmDisplayed) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("PERIGO, FOGO!");
      lcd.setCursor(0, 1);
      lcd.print("DETECTADO!");
      alarmDisplayed = true;
    }

    digitalWrite(ledPin, HIGH);

    tone(buzzerPin, 1800);
    delay(200);
    tone(buzzerPin, 1000);
    delay(200);

    return;
  }

  // ───── MODO NORMAL ─────
  digitalWrite(ledPin, LOW);
  noTone(buzzerPin);
}
