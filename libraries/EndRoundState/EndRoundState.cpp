#include "GameEngine.h"
#include "GameState.h"
#include "EndRoundState.h"
#include "RouletteState.h"
#include "Arduino.h"
#include "IntroState.h"
#include "GameObject.h"
#include "MafiaOne.h"
#include "MafiaTwo.h"
#include "RouletteMachine.h"
#include "BuzzerHandler.h"
#include "GameScreen.h"

EndRoundState* EndRoundState::s_instance = NULL;

EndRoundState* EndRoundState::getInstance() {
   if (!s_instance)
    s_instance = new EndRoundState;
  return s_instance;
}


void EndRoundState::Init()
{
	
	_DEBUG = true;

	if(_DEBUG) Serial.println(F("EndRoundState Init..."));

	RouletteMachine::getInstance()->LedOff();

	if(MafiaOne::getInstance()->isAlive() == false || MafiaTwo::getInstance()->isAlive() == false) _gameOver = true;
	else _gameOver = false;

	_stateEnd = false;



}

void EndRoundState::Cleanup()
{

	if(_DEBUG) Serial.println(F("EndRoundState Cleanup..."));
	GameScreen::getInstance()->Clear();
}

void EndRoundState::HandleEvents() {

}


void EndRoundState::Update() 
{ 
	if(!_stateEnd) {

		//do something interesting
	
	} else {
		if(!_gameOver) GameEngine::getInstance()->ChangeState(RouletteState::getInstance());
		else GameEngine::getInstance()->ChangeState(IntroState::getInstance());
	}

	

	// Serial.println("EndRoundState Update...");

}


void EndRoundState::Draw() 
{
	// Serial.println("EndRoundState Draw...");
	if(_gameOver) {


		GameScreen::getInstance()->Clear();

		if(MafiaOne::getInstance()->isAlive()) {
			Serial.println(F("P1 HAS ELIMINATED ALL P2 MAFIAS"));
			GameScreen::getInstance()->Print(F("P1 VICTORY"), 6, 3);
			GameScreen::getInstance()->Draw(FLAG_ANIM_1, 8, 0);; 

			if(_DEBUG) Serial.println(F("Play BUZZ_VICTORY"));
			BuzzerHandler::getInstance()->Buzz(BUZZ_VICTORY);				
		} 
		else if(MafiaTwo::getInstance()->isAlive()) {
			Serial.println(F("P2 HAS ELIMINATED ALL P1 MAFIAS"));
			GameScreen::getInstance()->Print(F("P2 VICTORY"), 6, 3);
			GameScreen::getInstance()->Draw(FLAG_ANIM_1, 8, 0);

			if(_DEBUG) Serial.println(F("Play BUZZ_VICTORY"));
			BuzzerHandler::getInstance()->Buzz(BUZZ_VICTORY);
		} 
		else {
			Serial.println(F("BOTH MAFIA LOSE"));
			GameScreen::getInstance()->Print(F("GAME OVER"), 6, 3);
			GameScreen::getInstance()->Draw(DEATH, 8, 0);
			if(_DEBUG) Serial.println(F("Play BUZZ_GAMEOVER"));
			BuzzerHandler::getInstance()->Buzz(BUZZ_GAMEOVER);	
		}
		delay(5000);
		GameEngine::getInstance()->NextRound(false);
		
		_stateEnd = true;

		
	} else {


		GameScreen::getInstance()->Print(F("P1:"), 4, 1); 

		for(uint8_t i = 0; i < MafiaOne::getInstance()->Members(); i++){
			// GameScreen::getInstance()->Print(F("O"), 10+i, 1); 
			GameScreen::getInstance()->Draw(MAFIAONE, 8+(i*2)+1, 0);
		}

		// for(uint8_t i = 0; i < 5-MafiaOne::getInstance()->Members(); i++){
		// 	GameScreen::getInstance()->Print(F("X"), 14-i, 1); 
		// }

		GameScreen::getInstance()->Print(F("P2:"), 4, 3); 
		for(uint8_t i = 0; i < MafiaTwo::getInstance()->Members(); i++){
			GameScreen::getInstance()->Draw(MAFIATWO, 8+(i*2)+1, 2);
		}

		// for(uint8_t i = 0; i < 5-MafiaTwo::getInstance()->Members(); i++){
		// 	GameScreen::getInstance()->Print(F("X"), 14-i, 2); 
		// }

		BuzzerHandler::getInstance()->Buzz(BUZZ_NEXT_ROUND);
		delay(2000);

		GameEngine::getInstance()->NextRound(true);

		_stateEnd = true;
		
	}

	
}

