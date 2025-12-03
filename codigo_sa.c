#include <LiquidCrystal_I2C.h>

// Endereço do LCD (0x27 ou 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int fireSensorPin = 7; // Sensor de chama

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(fireSensorPin, INPUT_PULLUP);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sistema Fogo");
  lcd.setCursor(0, 1);
  lcd.print("Monitorando...");
}

void loop() {
  int fireDetected = digitalRead(fireSensorPin);

  if (fireDetected == LOW) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ALERTA!");
    lcd.setCursor(0, 1);
    lcd.print("FOGO DETECTADO");
  }
}
