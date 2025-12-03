#include <LiquidCrystal_I2C.h>

// -------------------- LCD --------------------
LiquidCrystal_I2C lcd(0x27, 16, 2);

// -------------------- Pinos -------------------
const int fireSensorPin = 7;
const int resetButtonPin = 6;
const int ledPin = 8;
const int buzzerPin = 13;

// -------------------- Estado ------------------
bool alarmActive = false;
bool alarmDisplayed = false;
unsigned long lastButtonPress = 0;

// -------------------- Setup -------------------
void setup() {
  Serial.begin(9600);
  
  lcd.init();
  lcd.backlight();

  pinMode(fireSensorPin, INPUT_PULLUP);
  pinMode(resetButtonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sistema de Fogo");
  lcd.setCursor(0, 1);
  lcd.print("Aguardando...");
}

// -------------------- Loop --------------------
void loop() {
  int fireDetected = digitalRead(fireSensorPin);
  int resetPressed = digitalRead(resetButtonPin);

  // --- Detectou fogo ---
  if (fireDetected == LOW && !alarmActive) {
    alarmActive = true;
    alarmDisplayed = false;
  }

  // --- Reset (com debounce) ---
  if (resetPressed == LOW && millis() - lastButtonPress > 300) {
    lastButtonPress = millis();

    if (alarmActive) {
      alarmActive = false;
      noTone(buzzerPin);
      digitalWrite(ledPin, LOW);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Reset concluido");
      lcd.setCursor(0, 1);
      lcd.print("Monitorando...");
      delay(2000);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Sistema de Fogo");
      lcd.setCursor(0, 1);
      lcd.print("Aguardando...");
    }
  }

  // --- Modo alarme ---
  if (alarmActive) {
    if (!alarmDisplayed) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("!!! ALERTA !!!");
      lcd.setCursor(0, 1);
      lcd.print("FOGO DETECTADO");
      alarmDisplayed = true;
    }

    digitalWrite(ledPin, HIGH);

    tone(buzzerPin, 1800);
    delay(180);
    tone(buzzerPin, 1000);
    delay(180);
    return;
  }

  // --- Modo normal ---
  digitalWrite(ledPin, LOW);
  noTone(buzzerPin);
}
