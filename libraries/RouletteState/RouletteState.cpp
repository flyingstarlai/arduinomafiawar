#include "GameEngine.h"
#include "GameState.h"
#include "RouletteState.h"
#include "SlapState.h"
#include "Arduino.h"
#include  "InputHandler.h"
#include "GameObject.h"
#include "RouletteMachine.h"
#include "MafiaOne.h"
#include "BuzzerHandler.h"
#include "GameScreen.h"
#include "MafiaOne.h"
#include "MafiaTwo.h"

RouletteState* RouletteState::s_instance = NULL;

RouletteState* RouletteState::getInstance() {
   if (!s_instance)
    s_instance = new RouletteState;
  return s_instance;
}


void RouletteState::Init()
{
	_DEBUG = false;
	if(_DEBUG) Serial.println(F("RouletteState Init..."));

	RouletteMachine::getInstance()->Reset();
	_bingo = NONE;
	_loopMills = 0;

	GameScreen::getInstance()->Print(F("ROUND"), 6, 1);
	uint8_t round = GameEngine::getInstance()->Round();
	if(round < 10) {
		GameScreen::getInstance()->Print(F("0"), 12, 1);
		GameScreen::getInstance()->Print(String(round), 13, 1);
	} else GameScreen::getInstance()->Print(String(round), 12, 1);

	GameScreen::getInstance()->Print(String(MafiaOne::getInstance()->Members()), 7, 2);
	GameScreen::getInstance()->Print(F("VS"), 9, 2);
	GameScreen::getInstance()->Print(String(MafiaTwo::getInstance()->Members()), 12, 2);
	delay(2000);
	GameScreen::getInstance()->Clear();
	if(_DEBUG) Serial.println(F("Play BUZZ_ROULETTE"));
	GameScreen::getInstance()->Draw(KAISHI, 8, 1);
	BuzzerHandler::getInstance()->Buzz(BUZZ_ROULETTE);
	GameScreen::getInstance()->Clear();


}

void RouletteState::Cleanup()
{

	if(_DEBUG) Serial.println(F("RouletteState Cleanup..."));
	GameScreen::getInstance()->Clear();
}


void RouletteState::HandleEvents()
{
	if(_DEBUG) Serial.println(F("RouletteState HandleEvents..."));	
	
}

void RouletteState::Update() 
{
	if(_DEBUG) {
	 	Serial.print(F("RouletteState Update... "));
		Serial.println(_bingo);
	}

	if(_bingo == NONE) 
		_bingo = RouletteMachine::getInstance()->Roll();
	else 
		GameEngine::getInstance()->ChangeState(SlapState::getInstance());

}

void RouletteState::Draw() 
{
	if(_DEBUG) Serial.println(F("RouletteState Draw..."));
	GameScreen::getInstance()->Print(F("MAFIA"), 9, 1);
	GameScreen::getInstance()->Print(F("WAR"), 9, 2);
	if(_loopMills % 2 == 0) GameScreen::getInstance()->Draw(SLIME_ANIM_1, 6, 1);
	else GameScreen::getInstance()->Draw(SLIME_ANIM_2, 6, 1);
	_loopMills++;
	
}



