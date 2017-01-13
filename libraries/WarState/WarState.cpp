#include "GameEngine.h"
#include "GameState.h"
#include "WarState.h"
#include "RouletteState.h"
#include "Arduino.h"
#include  "InputHandler.h"
#include "GameObject.h"
#include "MafiaOne.h"
#include "MafiaTwo.h"
#include "EndRoundState.h"
#include "RouletteMachine.h"
#include "BuzzerHandler.h"
#include "GameScreen.h"

WarState* WarState::s_instance = NULL;

WarState* WarState::getInstance() {
   if (!s_instance)
    s_instance = new WarState;
  return s_instance;
}


void WarState::Init()
{
	_DEBUG = false;
	if(_DEBUG) Serial.println(F("WarState Init..."));

	if(MafiaOne::getInstance()->isAttacker()) _attacker = ATTACKER_IS_P1;
	else _attacker = ATTACKER_IS_P2;


	_timer = 150;
	_subState = LISTEN;
	_stateResult = NONE;

	if(_DEBUG) Serial.println(F("Play BUZZ_WAR_BEGIN"));
	GameScreen::getInstance()->Draw(WAR_BEGIN, 8, 0);
	if(MafiaOne::getInstance()->isAttacker()) {
		GameScreen::getInstance()->Print(F("P1 ATTACK"), 6, 2); 
		GameScreen::getInstance()->Print(F("P2 DEFEND"), 6, 3);
	} else {
		GameScreen::getInstance()->Print(F("P1 DEFEND"), 6, 2); 
		GameScreen::getInstance()->Print(F("P2 ATTACK"), 6, 3);
	}
 
	BuzzerHandler::getInstance()->Buzz(BUZZ_WAR_BEGIN);	

	delay(3000);
	GameScreen::getInstance()->Clear();
	GameScreen::getInstance()->Draw(BUTTONUP, 1, 0); //1
	GameScreen::getInstance()->Draw(BUTTONUP, 3, 2); //2
	GameScreen::getInstance()->Draw(BUTTONUP, 17, 0); //3
	GameScreen::getInstance()->Draw(BUTTONUP, 15, 2); //4


}

void WarState::Cleanup()
{
	if(_DEBUG) Serial.println(F("WarState Cleanup..."));
	GameScreen::getInstance()->Clear();
	_attacker = 0;
	_timer = 0;
	_subState = 0;
	_stateResult = 0;
}


void WarState::HandleEvents()
{

	switch(_subState) {
		case LISTEN:
			MafiaOne::getInstance()->Move(RouletteMachine::getInstance()->Bingo());
			MafiaTwo::getInstance()->Move(RouletteMachine::getInstance()->Bingo());
			break;
		case COMPARE:
			break;
		case RESULT:
			 break;
		case CHANGESTATE:
			 break;
	}

}

void WarState::Update() 
{ 

	switch(_subState) {
		case LISTEN:
			_doListen();
			break;
		case COMPARE:
			_doCompare(MafiaOne::getInstance()->getMove(), MafiaTwo::getInstance()->getMove());
			break;
		case RESULT:
			_doResult();
			break;
		case CHANGESTATE:
			_doChangeSatate();
			break;
	}


}

void WarState::Draw() 
{

	switch(_subState) {
		case LISTEN:
			if(_timer <= 0) _subState = COMPARE;
			break;
		case COMPARE:
			_displayCompare(P1MOVE, MafiaOne::getInstance()->getMove());
			_displayCompare(P2MOVE, MafiaTwo::getInstance()->getMove());
			delay(2000);		
			if(_stateResult != NONE) _subState = RESULT;
			break;
		case RESULT:
			GameScreen::getInstance()->Clear();
			_displayResult();
			delay(2000);
			_subState = CHANGESTATE;
			break;
	}

}




void WarState::_doListen() {
	if(_timer > 0) _timer--;
} 


void WarState::_doCompare(uint8_t p1Move, uint8_t p2Move) {

	if(p1Move != p2Move) {
		Serial.println("move different");
		if(_attacker == ATTACKER_IS_P1) _stateResult = P1_ATTACK_SUCCESS;
		else _stateResult = P2_ATTACK_SUCCESS;
	} else {
		Serial.println("move same");
		if(_attacker == ATTACKER_IS_P1) _stateResult = P1_ATTACK_FAILED;
		else _stateResult = P2_ATTACK_FAILED;	
	}

	
} 

void WarState::_displayCompare(uint8_t player, uint8_t move) {
	if(_DEBUG) {
		Serial.print(F("move: "));
		Serial.print(move);
	} 

	GameScreen::getInstance()->Print(F("Times Up!"), 5, 1);
	switch(move){
		case LEFT:
			if(player == P1MOVE ) GameScreen::getInstance()->Draw(BUTTONDOWN, 1, 0);
			else if(player == P2MOVE) GameScreen::getInstance()->Draw(BUTTONDOWN, 15, 2);
			break;
		case RIGHT:
			if(player == P1MOVE ) GameScreen::getInstance()->Draw(BUTTONDOWN, 3, 2);
			else if(player == P2MOVE) GameScreen::getInstance()->Draw(BUTTONDOWN, 17, 0);
			break;
		case CENTER:

			if(player == P1MOVE ) {
				GameScreen::getInstance()->Draw(BUTTONDOWN, 1, 0);
				GameScreen::getInstance()->Draw(BUTTONDOWN, 3, 2);
			}
			else if(player == P2MOVE) {
				GameScreen::getInstance()->Draw(BUTTONDOWN, 15, 2);
				GameScreen::getInstance()->Draw(BUTTONDOWN, 17, 0);
			} 
			break;

		case NONE:
			break;

	}

	if(_attacker == ATTACKER_IS_P1) {
		if(player == P1MOVE && move != NONE) BuzzerHandler::getInstance()->Buzz(BUZZ_ATTACK_MOVE);
		else BuzzerHandler::getInstance()->Buzz(BUZZ_GUARD_MOVE);
	} else {
		if(player == P1MOVE && move != NONE) BuzzerHandler::getInstance()->Buzz(BUZZ_GUARD_MOVE);
		else BuzzerHandler::getInstance()->Buzz(BUZZ_ATTACK_MOVE);
	}
	
}
	

void WarState::_doResult() 
{
	
	if(_stateResult != NONE)
	switch(_stateResult) {
		case P1_ATTACK_SUCCESS:
			MafiaTwo::getInstance()->Dead();
			break;
		case P1_ATTACK_FAILED:
			break;
		case P2_ATTACK_SUCCESS:
			MafiaOne::getInstance()->Dead();
			break;
		case P2_ATTACK_FAILED:
			break;
	}
}


void WarState::_displayResult() 
{
	
	switch(_stateResult) {
		case P1_ATTACK_SUCCESS:

			GameScreen::getInstance()->Print(F("P1 SUCCESS"), 5, 3);
			for(uint8_t i = 0; i < 2; i++) {
				GameScreen::getInstance()->Draw(FLAG_ANIM_1, 8, 0);
				delay(500);
				GameScreen::getInstance()->Draw(FLAG_ANIM_2, 8, 0);
				delay(500);
			}
			BuzzerHandler::getInstance()->Buzz(BUZZ_ATTACK_SUCCESS);
			GameScreen::getInstance()->Clear();
			delay(500);
			GameScreen::getInstance()->Print(F("P2 DIED"), 6, 3);
			GameScreen::getInstance()->Draw(SKULL, 8, 0);
			break;
		case P1_ATTACK_FAILED:
			GameScreen::getInstance()->Print(F("P1 FAILED"), 5, 3);
			GameScreen::getInstance()->Draw(SAD, 8, 0);
			BuzzerHandler::getInstance()->Buzz(BUZZ_ATTACK_FAILED);
			delay(3000);			
			break;
		case P2_ATTACK_SUCCESS:
			GameScreen::getInstance()->Print(F("P2 SUCCESS"), 5, 3);
			for(uint8_t i = 0; i < 2; i++) {
				GameScreen::getInstance()->Draw(FLAG_ANIM_1, 8, 0);
				delay(500);
				GameScreen::getInstance()->Draw(FLAG_ANIM_2, 8, 0);
				delay(500);
			}
			BuzzerHandler::getInstance()->Buzz(BUZZ_ATTACK_SUCCESS);
			GameScreen::getInstance()->Clear();
			delay(500);
			GameScreen::getInstance()->Print(F("P1 DIED"), 6, 3);
			GameScreen::getInstance()->Draw(SKULL, 8, 0);
			break;
		case P2_ATTACK_FAILED:
			GameScreen::getInstance()->Print(F("P2 FAILED"), 5, 3);
			GameScreen::getInstance()->Draw(SAD, 8, 0);
			BuzzerHandler::getInstance()->Buzz(BUZZ_ATTACK_FAILED);
			delay(3000);
			break;
	}
}

void WarState::_doChangeSatate() 
{
	
	GameEngine::getInstance()->ChangeState(EndRoundState::getInstance()); 
	
}
