#include "GameEngine.h"
#include "GameState.h"
#include "MafiaTwo.h"
#include "Arduino.h"
#include  "InputHandler.h"
#include "GameObject.h"
#include "BuzzerHandler.h"


MafiaTwo* MafiaTwo::s_instance = NULL;

MafiaTwo* MafiaTwo::getInstance() {
   if (!s_instance)
    s_instance = new MafiaTwo;
  return s_instance;
}


void MafiaTwo::Init(uint16_t analogController)
{

  _DEBUG = true;

  _gameController = analogController;
  _mafiaMembers = 0;



  if(_DEBUG) {
    Serial.print(F("Initialize MafiaTwo with analog "));
    Serial.print(_gameController);
    Serial.println(F(" game controller.."));

  }

  Reset();


}

void MafiaTwo::Create(uint8_t mafias) {
  if(_DEBUG) Serial.println(F("P2 recruiting mafias"));
  _mafiaMembers = mafias;
}

void MafiaTwo::Reset() {

  _slapRespond = NONE;
  _slapTime = NONE;

  _attacker = false;
  _move = NONE;
  _moveCount = 3;

}

void MafiaTwo::Slap(uint8_t time)
{
  uint8_t button = readButton();
    if(button != NONE) {
      if(_slapRespond == NONE) {
        _slapRespond = button;
        _slapTime = time;

        if(_DEBUG) Serial.println(F("Play BUZZ_SLAP"));
        BuzzerHandler::getInstance()->Buzz(BUZZ_SLAP);  

      } 
      else
      {
        if(_DEBUG) {
          Serial.print(F("P2 Slap: ")); 
          Serial.println(_slapRespond);
        }
        
      }
  }
}


uint8_t MafiaTwo::readButton()
{

   return InputHandler::getInstance()->readInput(_gameController);
}

bool MafiaTwo::checkSlapRespond(uint8_t bingo)
{
  bool check = NONE;



  switch (bingo) {
    case SHERIFF: check = _isEscaped(); break;
    case MADBULL: check = _isBlocked(); break;
    default: check = _hasWeapon(); break;
  }

  return check;
}


void MafiaTwo::Dead()
{
   if(_DEBUG) {
    Serial.println(F("P2's mafia died"));
   }
   if(_mafiaMembers > 0) _mafiaMembers--;
}


void MafiaTwo::Move(uint8_t bingo) {
    uint8_t button = readButton();
    if(button != NONE && _moveCount > 0) {
        if(_DEBUG) Serial.println(F("Play BUZZ_SLAP"));
        // BuzzerHandler::getInstance()->Buzz(BUZZ_SLAP);  

        if(bingo == GUN_1 || bingo == GUN_2) {
            if(button != BOTH) _move = button;
        }
        else if (bingo == CANNON_1|| bingo == CANNON_2) {
            _move = button;
        }

        _moveCount--;
    }

  
  if(_DEBUG) {
    Serial.print(F("P2 Move: " )); 
    Serial.println(_move);
  }

    
}

void MafiaTwo::Weapon()
{
  if(_DEBUG) {
    Serial.println(F("P2 READY TO ATTACK"));
    delay(1000);
  }

  _attacker = true;

}



bool MafiaTwo::_isEscaped() {
  if(_slapRespond == RED) {
    if(_DEBUG) Serial.println(F("P2 escapes from Sheriff"));
    return true;
  } else {
    if(_DEBUG) Serial.println(F("P2 jailed by Sheriff"));
    return false;
  }

}

bool MafiaTwo::_isBlocked() {

  
  if(_slapRespond == BOTH) {
    if(_DEBUG) Serial.println(F("P2 dodges Mad Bull"));
    return true;
  } else {
    if(_DEBUG) Serial.println(F("P2 hit by Mad Bull"));
    return false;
  }

}


bool MafiaTwo::_hasWeapon() {
  if(_slapRespond == BLUE) {
      if(_DEBUG) Serial.println(F("P2 wins the weapon"));
      return true;
    } else {
      if(_DEBUG) Serial.println(F("P2 loses the weapon"));
      return false;
  }
}

bool MafiaTwo::isAlive() {
  if(_mafiaMembers > 0) return true;
  else return false;

}