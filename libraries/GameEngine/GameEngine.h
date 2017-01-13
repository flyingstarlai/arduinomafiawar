
#ifndef GameEngine_h
#define GameEngine_h



#include <LinkedList.h>
#include "Arduino.h"


class GameState;



class GameEngine
{
public:

	void Init();
	void Cleanup();

	void ChangeState(GameState* state);

	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return _running; }
	void Quit() { Serial.println("Quitting.."); _running = false; }

	uint8_t Round() { return _round; }
	void NextRound(bool nextRound);


	static GameEngine* getInstance();


private:
	bool _DEBUG;
	// the stack of states
	LinkedList<GameState*> states = LinkedList<GameState*>();
	bool _running;

	uint8_t _round;

	static GameEngine* s_instance;
};

#endif
