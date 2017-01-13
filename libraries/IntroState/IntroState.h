#ifndef IntroState_h
#define IntroState_h

#include "GameState.h"

class IntroState : public GameState
{
public:
	void Init();
	void Cleanup();

	void HandleEvents();
	void Update();
	void Draw();


	static IntroState* getInstance();

protected:
	IntroState() { }

private:
	static IntroState* s_instance;

	bool _DEBUG;

	uint8_t _loopMills;
};

#endif

