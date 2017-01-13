#include "GameEngine.h"
#include "GameState.h"
#include "Arduino.h"
#include "GameObject.h"
#include "RouletteMachine.h"
#include "InputHandler.h"
#include "MafiaOne.h"
#include "MafiaTwo.h"
#include "BuzzerHandler.h"
#include "GameScreen.h"
#include <LiquidCrystal_I2C.h>

GameEngine*  GameEngine::s_instance = NULL;

GameEngine* GameEngine::getInstance() {
  if (!s_instance)
    s_instance = new GameEngine;
  return s_instance;
}

void GameEngine::Init()
{
	_DEBUG = false;
	if(_DEBUG) Serial.println(F("GameEngine Init..."));
	RouletteMachine::getInstance()->Init(8, 9, 10, 11, 12, 13);


  	InputHandler::getInstance()->Init(A1, A2);

  	MafiaOne::getInstance()->Init(A1);

  	MafiaTwo::getInstance()->Init(A2);

  	BuzzerHandler::getInstance()->Init(7);

	LiquidCrystal_I2C gameScreen(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
  	GameScreen::getInstance()->Init(&gameScreen);
  	GameScreen::getInstance()->Clear();

	_running = true;

	_round = 1;

}


void GameEngine::Cleanup()
{
	// cleanup the all states
	while ( states.size() > 0) {
		states.get(states.size()-1)->Cleanup();
		states.pop();
	}

	if(_DEBUG) Serial.println(F("GameEngine Cleanup..."));

}

void GameEngine::ChangeState(GameState* state) 
{
	if(_DEBUG) Serial.println(F("GameEngine ChangeState"));

	// cleanup the current state
	if ( states.size() > 0) {
		states.get(states.size()-1)->Cleanup();
		states.set(states.size()-1, state);
	
	} else {
		states.add(state);
	}

	
	states.get(states.size()-1)->Init();
}



void GameEngine::HandleEvents() 
{
	// let the state handle events
	states.get(states.size()-1)->HandleEvents();
}

void GameEngine::Update() 
{
	// let the state update the game
	states.get(states.size()-1)->Update();
}

void GameEngine::Draw() 
{
	// let the state draw the screen
	states.get(states.size()-1)->Draw();
}

void GameEngine::NextRound(bool nextRound) {
	if(nextRound) _round++;
	else _round = 1;
	
}