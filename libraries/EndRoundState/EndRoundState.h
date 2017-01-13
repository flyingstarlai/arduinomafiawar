#ifndef EndRoundState_h
#define EndRoundState_h

#include "GameState.h"

class EndRoundState : public GameState
{
public:
	void Init();
	void Cleanup();

	void HandleEvents();
	void Update();
	void Draw();


	static EndRoundState* getInstance();

protected:
	EndRoundState() { }

private:
	static EndRoundState* s_instance;
	bool _DEBUG;

	bool _gameOver;
	bool _stateEnd;
};

#endif

