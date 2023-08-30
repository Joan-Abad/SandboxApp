#pragma once
#include "Engine/YorkiEngineApp.h"

class GameEntity;
class Input;

class SandboxApp : public YorkieEngineApp
{
public:
	SandboxApp();

protected:
	virtual void OnCreateApplicationCallback() override;
	virtual void OnUpdate() override;
	virtual void OnPostUpdate() override;
private: 
	GameEntity* rE;
	GameEntity* secondRo;
	GameEntity* thirdRE;
	Input* input;
};

