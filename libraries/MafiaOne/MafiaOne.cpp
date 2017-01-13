#include "GameEngine.h"
#include "GameState.h"
#include "MafiaOne.h"
#include "Arduino.h"
#include  "InputHandler.h"
#include "GameObject.h"
#include "BuzzerHandler.h"


MafiaOne* MafiaOne::s_instance = NULL;

MafiaOne* MafiaOne::getInstance() {
   if (!s_instance)
    s_instance = new MafiaOne;
  return s_instance;
}


void MafiaOne::Init(uint16_t analogController)
{

  _DEBUG = true;

	_gameController = analogController;
  _mafiaMembers = 0;



  if(_DEBUG) {
    Serial.print(F("Initialize MafiaOne with analog "));
    Serial.print(_gameController);
    Serial.println(F(" game controller.."));

  }

  Reset();


}

void MafiaOne::Create(uint8_t mafias) {
  if(_DEBUG) Serial.println(F("P1 recruiting mafias"));
  _mafiaMembers = mafias;
}

void MafiaOne::Reset() {

  _slapRespond = NONE;
  _slapTime = NONE;

  _attacker = false;
  _move = NONE;
  _moveCount = 3;

}

void MafiaOne::Slap(uint8_t time)
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
          Serial.print(F("P1 Slap: ")); 
          Serial.println(_slapRespond);
        }
        
  	  }
  }
}


uint8_t MafiaOne::readButton()
{

   return InputHandler::getInstance()->readInput(_gameController);
}

bool MafiaOne::checkSlapRespond(uint8_t bingo)
{
  bool check = NONE;



  switch (bingo) {
    case SHERIFF: check = _isEscaped(); break;
    case MADBULL: check = _isBlocked(); break;
    default: check = _hasWeapon(); break;
  }

  return check;
}


void MafiaOne::Dead()
{
   if(_DEBUG) {
    Serial.println(F("P1's mafia died"));
   }
   if(_mafiaMembers > 0) _mafiaMembers--;
}


void MafiaOne::Move(uint8_t bingo) {
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
    Serial.print(F("P1 Move: " )); 
    Serial.println(_move);
  }

    
}

void MafiaOne::Weapon()
{
  if(_DEBUG) {
    Serial.println(F("P1 READY TO ATTACK"));
    delay(1000);
  }

  _attacker = true;

}



bool MafiaOne::_isEscaped() {
  if(_slapRespond == RED) {
    if(_DEBUG) Serial.println(F("P1 escapes from Sheriff"));
    return true;
  } else {
    if(_DEBUG) Serial.println(F("P1 jailed by Sheriff"));
    return false;
  }

}

bool MafiaOne::_isBlocked() {

  
  if(_slapRespond == BOTH) {
    if(_DEBUG) Serial.println(F("P1 dodges Mad Bull"));
    return true;
  } else {
    if(_DEBUG) Serial.println(F("P1 hit by Mad Bull"));
    return false;
  }

}


bool MafiaOne::_hasWeapon() {
  if(_slapRespond == BLUE) {
      if(_DEBUG) Serial.println(F("P1 wins the weapon"));
      return true;
    } else {
      if(_DEBUG) Serial.println(F("P1 loses the weapon"));
      return false;
  }
}

bool MafiaOne::isAlive() {
  if(_mafiaMembers > 0) return true;
  else return false;

}