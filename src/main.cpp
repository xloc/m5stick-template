#include <Arduino.h>
#include <M5StickCPlus.h>

void IRAM_ATTR reset_isr()
{
  ESP.restart();
}

void setup()
{
  // set middle button as reset button
  pinMode(BUTTON_A_PIN, INPUT_PULLDOWN);
  attachInterrupt(BUTTON_A_PIN, reset_isr, RISING);

  M5.begin();
  Serial.begin(115200);
  Serial.println("\nReady.");
}

void loop()
{
}
