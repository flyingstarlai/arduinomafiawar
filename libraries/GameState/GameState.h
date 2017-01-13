
#ifndef GameState_h
#define GameState_h

#include "GameEngine.h"

enum SubState {
	LISTEN = 1,
	COMPARE = 2,
	RESULT = 3,
	CHANGESTATE = 4
};


class GameState
{
public:
	virtual void Init() = 0;
	virtual void Cleanup() = 0;

	virtual void HandleEvents() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	void ChangeState(GameState* state) {
		GameEngine::getInstance()->ChangeState(state);
	}

protected:
	GameState() { }
};

#endif

