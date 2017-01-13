
#include <GameState.h>
#include <IntroState.h>
#include <GameEngine.h>
#include <stdint.h>
#include <avr/pgmspace.h>




  
  
  void setup() {  
    Serial.begin(9600); //Start logger
  // BuzzerHandler::getInstance()->Init(7);
    
  }


void loop() {
  GameEngine::getInstance()->Init(); //create game object: players, sounds, events etc

   
  
  GameEngine::getInstance()->ChangeState( IntroState::getInstance()); //jump into IntroState

  while(GameEngine::getInstance()->Running()) { //running the game
 
      GameEngine::getInstance()->HandleEvents(); // handling button from players
      GameEngine::getInstance()->Update(); // update game event
      GameEngine::getInstance()->Draw(); // print game event to LCD
   
  }

  GameEngine::getInstance()->Cleanup(); //detroy game object
   

}




