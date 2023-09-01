#pragma once
#include "Engine/YorkiEngineApp.h"

class GameEntity;
class Cube;
class Input;

class SandboxApp : public YorkieEngineApp
{
public:
	SandboxApp();

protected:
	virtual void OnCreateApplicationCallback() override;
	virtual void OnUpdate(float deltaTime) override;
	virtual void OnPostUpdate() override;
private: 
	GameEntity* gE;
	GameEntity* jolieCubeEntity;
	GameEntity* secondTexturedEntity;
	GameEntity* m_BasicLight;
	GameEntity* m_floor;
	Input* input;
	float lightSpeed = 50;
};

