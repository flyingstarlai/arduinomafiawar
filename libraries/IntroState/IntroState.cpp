#include "GameEngine.h"
#include "GameState.h"
#include "IntroState.h"
#include "RouletteState.h"
#include "Arduino.h"
#include  "InputHandler.h"
#include "GameObject.h"
#include "MafiaOne.h"
#include "MafiaTwo.h"
#include "CoinHandler.h"
#include "BuzzerHandler.h"
#include "GameScreen.h"


IntroState* IntroState::s_instance = NULL;

IntroState* IntroState::getInstance() {
   if (!s_instance)
    s_instance = new IntroState;
  return s_instance;
}


void IntroState::Init()
{
	_DEBUG = true;

	CoinHandler::getInstance()->Init(A3, 4);

	MafiaOne::getInstance()->Create(3);
	MafiaTwo::getInstance()->Create(3);

	if(_DEBUG) Serial.println(F("IntroState Init..."));
	// GameScreen::getInstance()->Draw(WAR_BEGIN, 8, 0);
	// GameScreen::getInstance()->Print(F("P1 ATTACK"), 6, 2); 
	// GameScreen::getInstance()->Print(F("P2 DEFEND"), 6, 3); 
	GameScreen::getInstance()->Draw(TSU, 8, 0);
	GameScreen::getInstance()->Print(F("Shoufu"), 7, 2);
	delay(5000);
	GameScreen::getInstance()->Clear();
	if(_DEBUG) Serial.println(F("Play BUZZ_INTRO"));
	BuzzerHandler::getInstance()->Buzz(BUZZ_INTRO);	

	if(_DEBUG) Serial.println(F("-----PLEASE INSERT COIN----"));
	
	delay(1000);
	GameScreen::getInstance()->Clear();
	CoinHandler::getInstance()->TurnIndicator(true);
	BuzzerHandler::getInstance()->Buzz(BUZZ_CLICK);	

	GameScreen::getInstance()->Print(F("MAFIAWAR"), 6, 2);
	GameScreen::getInstance()->Print(F("**"), 0, 0);
	GameScreen::getInstance()->Print(F("*"), 0, 1);
	GameScreen::getInstance()->Print(F("**"), 18, 0);
	GameScreen::getInstance()->Print(F("*"), 19, 1);
	GameScreen::getInstance()->Print(F("**"), 0, 3);
	GameScreen::getInstance()->Print(F("*"), 0, 2);
	GameScreen::getInstance()->Print(F("**"), 18, 3);
	GameScreen::getInstance()->Print(F("*"), 19, 2);
	GameScreen::getInstance()->Print(F("~"), 5, 2);
	GameScreen::getInstance()->Print(F("~"), 14, 2);
	    // _lcd->setCursor(x-2, y+2);
    // _lcd->print(F("MAFIAWAR"));

	_loopMills = 0;

	
}

void IntroState::Cleanup()
{

	if(_DEBUG) Serial.println(F("IntroState Cleanup..."));
	GameScreen::getInstance()->Clear();
}


void IntroState::HandleEvents()
{
	


	Serial.print("P1: ");
	Serial.println(MafiaOne::getInstance()->readButton());
	Serial.print("P2: ");
	Serial.println(MafiaTwo::getInstance()->readButton());
	
	// if(MafiaOne::getInstance()->readButton() == BOTH || MafiaTwo::getInstance()->readButton() == BOTH ) {
	// 	GameEngine::getInstance()->ChangeState(RouletteState::getInstance());
		
	// }

// CoinHandler::getInstance()->Insert();


	if(CoinHandler::getInstance()->Insert()) {
		if(_DEBUG) Serial.println(F("Play BUZZ_COIN_INSERTED"));
		BuzzerHandler::getInstance()->Buzz(BUZZ_COIN_INSERTED);	
		delay(1000);
		CoinHandler::getInstance()->TurnIndicator(false);
		GameEngine::getInstance()->ChangeState(RouletteState::getInstance());
	}


	
}

void IntroState::Update() 
{

	

}

void IntroState::Draw() 
{		
	
	if(_loopMills < 15) {
		GameScreen::getInstance()->Draw(TITLE_ANIM_1, 8, 0);
		GameScreen::getInstance()->Print(F("insert coin"), 5, 3);
	} else {
		GameScreen::getInstance()->Draw(TITLE_ANIM_2, 8, 0);
		if(_loopMills > 30) _loopMills = 0;
		GameScreen::getInstance()->Print(F("           "), 5, 3);
	}



	_loopMills++;
	
}

