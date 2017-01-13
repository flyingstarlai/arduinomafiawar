#include "GameEngine.h"
#include "GameState.h"
#include "SlapState.h"
#include "Arduino.h"
#include "InputHandler.h"
#include "GameObject.h"
#include "RouletteMachine.h"
#include "MafiaOne.h"
#include "MafiaTwo.h"
#include "WarState.h"
#include "EndRoundState.h"
#include "BuzzerHandler.h"
#include "GameScreen.h"

SlapState* SlapState::s_instance = NULL;

SlapState* SlapState::getInstance() {
   if (!s_instance)
    s_instance = new SlapState;
  return s_instance;
}


SlapState::~SlapState() {
	Cleanup();
}

void SlapState::Init()
{
	_DEBUG = true;

	
	MafiaOne::getInstance()->Reset();
	MafiaTwo::getInstance()->Reset();

	_bingo = RouletteMachine::getInstance()->Bingo();
	// _bingo = 1;
	int roundTimer = (500-(GameEngine::getInstance()->Round()*20));
	if(roundTimer > 200) _timer = roundTimer;
	else _timer = 200;
	// _capTimer = _timer;
	if(_DEBUG) {
		Serial.print("SlapState Init -> BINGO: ");
		Serial.println(_bingo);
	}
	_subState = LISTEN;
	_stateResult = NONE;

	GameScreen::getInstance()->Draw(BUTTONUP, 1, 0); //1
	GameScreen::getInstance()->Draw(BUTTONUP, 3, 2); //2
	GameScreen::getInstance()->Draw(BUTTONUP, 17, 0); //3
	GameScreen::getInstance()->Draw(BUTTONUP, 15, 2); //4
	GameScreen::getInstance()->Print(String(_bingo), 9, 1);
	BuzzerHandler::getInstance()->Buzz(BUZZ_CLICK);
	


}

void SlapState::Cleanup()
{

	if(_DEBUG) Serial.println(F("SlapState Cleanup..."));
	GameScreen::getInstance()->Clear();
	_bingo = 0;
	_timer = 0;
	_subState = 0;
	_stateResult = 0;

}


void SlapState::HandleEvents()
{
	
	switch(_subState) {
		case LISTEN:
			MafiaOne::getInstance()->Slap(_timer);
			MafiaTwo::getInstance()->Slap(_timer);
			break;
		case COMPARE:
			break;
		case RESULT:
			 break;
		case CHANGESTATE:
			 break;
	}
}

void SlapState::Update() 
{
	switch(_subState) {
		case LISTEN:
			_doListen();
			break;
		case COMPARE:
			_doCompare(MafiaOne::getInstance()->checkSlapRespond(_bingo), 
						MafiaTwo::getInstance()->checkSlapRespond(_bingo)); 
			break;
		case RESULT:
			if(_DEBUG) Serial.print(F("State Result: "));
			if(_DEBUG) Serial.println(_stateResult);
			_doResult();
			 break;
		case CHANGESTATE:
			 _doChangeSatate();
			 break;

	}

}

void SlapState::Draw() 
{
	// if(_DEBUG) Serial.print(F("Draw SubState: "));
	// if(_DEBUG) Serial.println(_subState);

	switch(_subState) {
		case LISTEN:
			// _doCountdown();
			// GameScreen::getInstance()->Print(F("Pick your response"), 2, 1);

			if(_timer <= 0) _subState = COMPARE;
			break;
		case COMPARE:
			// GameScreen::getInstance()->Clear();
			_displayCompare(P1SLAP, MafiaOne::getInstance()->getSlapRespond());
			_displayCompare(P2SLAP, MafiaTwo::getInstance()->getSlapRespond());
			// _displayCompare(P1SLAP, SLAP_BLUE);
			// _displayCompare(P2SLAP, SLAP_RED);
			delay(2000);		
			if(_stateResult != NONE) _subState = RESULT;
			break;
		case RESULT:
			_displayResult();
			delay(2000);
			_subState = CHANGESTATE;
			break;
	}

	
}

// void SlapState::_doCountdown() {
// 	switch((_capTimer / 5) - (_timer / 5))
// 	{
// 		case 1
// 	}
	
// 				/* code */
			
// }


void SlapState::_doListen() {
	if(_timer > 0) _timer--;
	if(_DEBUG) Serial.println(_timer);
}


void SlapState::_doCompare(uint8_t p1Respond, uint8_t p2Respond) 
{


	if(p1Respond == true && p2Respond == true) 
	{
		if(_DEBUG) Serial.println(F("both true"));
		uint8_t fasterPlayer = _compareTime(MafiaOne::getInstance()->getSlapTime(),
									MafiaTwo::getInstance()->getSlapTime());

		if(_bingo == MADBULL) {
			if(fasterPlayer == P1_FASTER) _stateResult = P1_DODGE_BULL;
			else _stateResult = P2_DODGE_BULL;
		} 
		else if(_bingo == SHERIFF){
			if(fasterPlayer == P1_FASTER) _stateResult = P1_ESCAPE_POLICE;
			else _stateResult = P2_ESCAPE_POLICE;
		} else {
			if(fasterPlayer == P1_FASTER) _stateResult = P1_WIN_WEAPON;
			else _stateResult = P2_WIN_WEAPON;
		}

	} 
	else 
	{
		if(p1Respond || p2Respond) 
		{
			if(_DEBUG) Serial.println(F("p1 / p2 true"));
			if(_bingo == MADBULL) {
				if(p1Respond) _stateResult = P1_DODGE_BULL;
				else _stateResult = P2_DODGE_BULL;
			} 
			else if(_bingo == SHERIFF){
				if(p1Respond) _stateResult = P1_ESCAPE_POLICE;
				else _stateResult = P2_ESCAPE_POLICE;
			} else {
				if(p1Respond) _stateResult = P1_WIN_WEAPON;
				else _stateResult = P2_WIN_WEAPON;
			}

		} 
		else {
			if(_DEBUG) Serial.println(F("both false"));
			if(_bingo == MADBULL) {
				_stateResult = P1P2_BULLED;
			} 
			else if(_bingo == SHERIFF){
				_stateResult = P1P2_JAILED;
			} else {
				_stateResult = P1P2_LOSE_WEAPON;
			}
		}
	}

}


void SlapState::_displayCompare(uint8_t player, uint8_t slap) {
	if(_DEBUG){
		Serial.println(player);
		Serial.println(slap);
	}

	GameScreen::getInstance()->Print(F("Times Up!"), 5, 1);
	switch(slap){
		case SLAP_BLUE:
			if(player == P1SLAP ) GameScreen::getInstance()->Draw(BUTTONDOWN, 1, 0);
			else if(player == P2SLAP) GameScreen::getInstance()->Draw(BUTTONDOWN, 15, 2);
			// if(player == P1SLAP ) {GameScreen::getInstance()->Print(F("P1 BLUE"), 2, 1);
			// else if(player == P2SLAP) GameScreen::getInstance()->Print(F("P2 BLUE"), 2, 2);
			break;
		case SLAP_RED:
			if(player == P1SLAP ) GameScreen::getInstance()->Draw(BUTTONDOWN, 3, 2);
			else if(player == P2SLAP) GameScreen::getInstance()->Draw(BUTTONDOWN, 17, 0);
			// if(player == P1SLAP )GameScreen::getInstance()->Print(F("P1 RED"), 2, 1);
			// else if(player == P2SLAP) GameScreen::getInstance()->Print(F("P2 RED"), 2, 2);
			break;
		case SLAP_BOTH:
			if(player == P1SLAP ) {
				GameScreen::getInstance()->Draw(BUTTONDOWN, 1, 0);
				GameScreen::getInstance()->Draw(BUTTONDOWN, 3, 2);
			}
			else if(player == P2SLAP) {
				GameScreen::getInstance()->Draw(BUTTONDOWN, 15, 2);
				GameScreen::getInstance()->Draw(BUTTONDOWN, 17, 0);
			} 
			// if(player == P1SLAP )GameScreen::getInstance()->Print(F("P1 BOTH"), 2, 1);
			// else if(player == P2SLAP) GameScreen::getInstance()->Print(F("P2 BOTH"), 2, 2);
			break;
		case NONE:
			// if(player == P1MOVE )GameScreen::getInstance()->Print(F("P1 MISS"), 2, 1);
			// else if(player == P2SLAP) GameScreen::getInstance()->Print(F("P2 MISS"), 2, 2);
			break;

	}

	BuzzerHandler::getInstance()->Buzz(BUZZ_COMPARED);
}



void SlapState::_doResult() {
	if(_stateResult != NONE) {
		switch(_stateResult) {
			case P1_WIN_WEAPON: MafiaOne::getInstance()->Weapon(); break;
			case P2_WIN_WEAPON: MafiaTwo::getInstance()->Weapon(); break;
			case P1P2_LOSE_WEAPON: break;
			case P1_DODGE_BULL: MafiaTwo::getInstance()->Dead(); break;
			case P2_DODGE_BULL: MafiaOne::getInstance()->Dead(); break;
			case P1P2_BULLED: MafiaOne::getInstance()->Dead(); MafiaTwo::getInstance()->Dead(); break;
			case P1_ESCAPE_POLICE: MafiaTwo::getInstance()->Dead(); break;
			case P2_ESCAPE_POLICE: MafiaOne::getInstance()->Dead(); break;
			case P1P2_JAILED: MafiaOne::getInstance()->Dead(); MafiaTwo::getInstance()->Dead(); break;
		}
	}
}


void SlapState::_doChangeSatate() 
{
	if(_bingo != SHERIFF &&
	 _bingo != MADBULL && 
	 _stateResult != 
	 P1P2_LOSE_WEAPON ) GameEngine::getInstance()->ChangeState(WarState::getInstance());
	else GameEngine::getInstance()->ChangeState(EndRoundState::getInstance());  
	
}





void SlapState::_displayResult() {
	GameScreen::getInstance()->Clear();
	switch(_stateResult) {
		case P1_WIN_WEAPON: 
			GameScreen::getInstance()->Draw(GUN_BIG, 8, 0);
			GameScreen::getInstance()->Print(F("P1 WIN"), 7, 3);
			BuzzerHandler::getInstance()->Buzz(BUZZ_GOT_WEAPON);
			break;
		case P2_WIN_WEAPON: MafiaTwo::getInstance()->Weapon();
			GameScreen::getInstance()->Draw(GUN_BIG, 8, 0);
			GameScreen::getInstance()->Print(F("P2 WIN"), 7, 3);
			BuzzerHandler::getInstance()->Buzz(BUZZ_GOT_WEAPON);
			break;
		case P1P2_LOSE_WEAPON:
			GameScreen::getInstance()->Print(F("P1 LOSE"), 6, 2);
			GameScreen::getInstance()->Print(F("P2 LOSE"), 6, 3);
			GameScreen::getInstance()->Draw(SAD, 8, 0);
			break;
		case P1_DODGE_BULL: 
			GameScreen::getInstance()->Print(F("P2 DIED"), 6, 2);
			GameScreen::getInstance()->Draw(SKULL, 8, 0);
			BuzzerHandler::getInstance()->Buzz(BUZZ_KILLED_BY_BULL);
			break;
		case P2_DODGE_BULL:
			GameScreen::getInstance()->Print(F("P1 DIED"), 6, 2);
			GameScreen::getInstance()->Draw(SKULL, 8, 0);
			BuzzerHandler::getInstance()->Buzz(BUZZ_KILLED_BY_BULL);
			break;
		case P1P2_BULLED:
			GameScreen::getInstance()->Print(F("P1 DIED"), 6, 2);
			GameScreen::getInstance()->Print(F("P2 DIED"), 6, 3);
			GameScreen::getInstance()->Draw(SKULL, 8, 0);
			BuzzerHandler::getInstance()->Buzz(BUZZ_KILLED_BY_BULL);
			break;
		case P1_ESCAPE_POLICE:
			GameScreen::getInstance()->Print(F("P2 DIED"), 6, 3);
			GameScreen::getInstance()->Draw(SKULL, 8, 0);
			BuzzerHandler::getInstance()->Buzz(BUZZ_JAILED);
			break; 
		case P2_ESCAPE_POLICE:
			GameScreen::getInstance()->Print(F("P1 DIED"), 6, 3);
			GameScreen::getInstance()->Draw(SKULL, 8, 0);
			BuzzerHandler::getInstance()->Buzz(BUZZ_JAILED);
			BuzzerHandler::getInstance()->Buzz(BUZZ_JAILED);
			BuzzerHandler::getInstance()->Buzz(BUZZ_JAILED);
			break;
		case P1P2_JAILED:
			MafiaOne::getInstance()->Dead();
			MafiaTwo::getInstance()->Dead();
			GameScreen::getInstance()->Print(F("P1 DIED"), 6, 2);
			GameScreen::getInstance()->Print(F("P2 DIED"), 6, 3);
			GameScreen::getInstance()->Draw(SKULL, 8, 0);
			BuzzerHandler::getInstance()->Buzz(BUZZ_JAILED);
			break;
	}
}



uint8_t SlapState::_compareTime(uint8_t p1Timer, uint8_t p2Timer) 
{
	
	uint8_t result;

	if(p1Timer == p2Timer) {
		result =_drawBalancing();

	}
	else if(p1Timer > p2Timer) result = P1_FASTER;
	else if(p1Timer < p2Timer) result = P2_FASTER;

    if(_DEBUG) {
		Serial.print(F("Comparing Slap Time: "));
		Serial.print(p1Timer);
		Serial.print(F(" to "));
		Serial.print(p2Timer);
		Serial.print(F(" is "));
		Serial.println(result);   	
    }

	return result;

	
}



uint8_t SlapState::_drawBalancing(){
	if(_DEBUG) Serial.println(F("draw balancing"));
	if(MafiaOne::getInstance()->Members() < MafiaTwo::getInstance()->Members()) return P1_FASTER;
	else if(MafiaOne::getInstance()->Members() > MafiaTwo::getInstance()->Members()) return P2_FASTER;
	else {
		if (random(10, 20) % 2 == 0)
        	return P1_FASTER;
    	else
        	return P2_FASTER;
	}
}


	


