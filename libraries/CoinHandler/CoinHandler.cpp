#include "Arduino.h"
#include "CoinHandler.h"
#include "GameObject.h"


CoinHandler*  CoinHandler::s_instance = NULL;

CoinHandler* CoinHandler::getInstance() {
  if (!s_instance)
    s_instance = new CoinHandler;
  return s_instance;
}

void CoinHandler::Init(uint16_t analogPin, uint8_t pin) {
  pinMode(pin, OUTPUT);
  _DEBUG = true;
  _analogPin = analogPin;
  _pin = pin;
  _inserted = false;
  
  if(_DEBUG) {
    Serial.print(F("Initialize LDR/LED at "));
    Serial.println(_analogPin);
    Serial.println("/");
    Serial.println(_pin);
  }

}

bool CoinHandler::Insert() {
if(_DEBUG) Serial.println(analogRead(_analogPin));

  if(analogRead(_analogPin) < 100) {
    if(_DEBUG) Serial.println(F("Coin is inserted.."));
     _inserted = true;
  } else _inserted = false;

  return _inserted;
}

void CoinHandler::TurnIndicator(bool on) {
  if(on) digitalWrite(_pin, HIGH);
  else digitalWrite(_pin, LOW);
}