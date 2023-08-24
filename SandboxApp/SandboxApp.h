#pragma once
#include "Engine/YorkiEngineApp.h"

class GameEntity;
class Input;

class SandboxApp : public YorkiEngineApp
{
public:
	SandboxApp();

protected:
	virtual void OnCreateApplicationCallback() override;
	virtual void OnPreDraw() override;
	virtual void OnPostDraw() override;
private: 
	GameEntity* ro;
	GameEntity* secondRo;
	GameEntity* thirdRo;
	Input* input;
};

