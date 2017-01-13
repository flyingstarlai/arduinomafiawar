#include "Arduino.h"
#include "RouletteMachine.h"


RouletteMachine* RouletteMachine::s_instance = NULL;

RouletteMachine* RouletteMachine::getInstance() {
   if (!s_instance)
    s_instance = new RouletteMachine;
  return s_instance;
}

void RouletteMachine::Init(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4, uint8_t pin5, uint8_t pin6) {

  _DEBUG = true;

  _leds[0] = pin1;
  _leds[1] = pin2;
  _leds[2] = pin3;
  _leds[3] = pin4;
  _leds[4] = pin5;
  _leds[5] = pin6;

 if(_DEBUG) Serial.print("Initialize Led in pin ");

  for(uint8_t i = 0;i < 6;i++){

    pinMode(_leds[i], OUTPUT);

    if(_DEBUG) {
      Serial.print(_leds[i]);
      Serial.print("  ");
    }
  }

  if(_DEBUG) {
    Serial.println("");
    Serial.println("Initialize random seed...");
  }
    

  randomSeed(analogRead(0));

}


void RouletteMachine::_illuminate(uint8_t i)
{
  digitalWrite(_leds[i], HIGH);
  delay(_delay);
  digitalWrite(_leds[i], LOW);
  _delay += 2;
  _current_bingo = i;

}

void RouletteMachine::LedOff()
{
  digitalWrite( _leds[_current_bingo], LOW);


}


void RouletteMachine::Reset() {
  uint8_t rmin = random(80, 100);
  uint8_t rmax = random(140, 160);
  uint8_t radd = random(1, 5);
  uint8_t raddMod = random(1, 5);

  _cap = random(rmin, rmax) + (radd * raddMod);
  _delay = 50;
  _current_bingo = 0;
  _real_bingo = 0;

  if(_DEBUG) {
    Serial.println("random(rmin, rmax) + (radd * raddMod) = ");
    Serial.println(rmin);
    Serial.println(rmax);
    Serial.println(radd);
    Serial.println(raddMod);
    Serial.println(_cap);
  }

}

int RouletteMachine::Roll()
{

  for(uint8_t i = 0; i<6; i++) {

    if(_DEBUG) Serial.print("Roulette is rolling...");

    if(_delay <= _cap) {
        _illuminate(i); 
    } else {
        //digitalWrite(_leds[_current_bingo], HIGH);
        digitalWrite(_leds[_current_bingo], HIGH);
        _real_bingo = _current_bingo + 1;
        if(_DEBUG) {
          Serial.print("Roueltte STOP at ");
          Serial.println(_real_bingo);        
        }

    }
  }

  if(_DEBUG) Serial.println("");

  return _real_bingo;

}