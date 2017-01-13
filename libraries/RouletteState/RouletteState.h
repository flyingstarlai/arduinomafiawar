#ifndef RouletteState_h
#define RouletteState_h

#include "GameState.h"

class RouletteState : public GameState
{
public:
	void Init();
	void Cleanup();

	void HandleEvents();
	void Update();
	void Draw();

	static RouletteState* getInstance();


protected:
	RouletteState() { }

private:
	bool _DEBUG;
	static RouletteState* s_instance;
	int _bingo;

	uint8_t _loopMills;

};

#endif

