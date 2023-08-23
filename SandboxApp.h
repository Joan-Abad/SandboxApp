#pragma once
#include "Application/YorkiEngineApp.h"
#include "Input/Controller.h"

class RenderObject;

class SandboxApp : public YorkiEngineApp
{
public:
	SandboxApp();

protected:
	virtual void OnCreateApplicationCallback() override;
	virtual void OnPreDraw() override;
	virtual void OnPostDraw() override;
private: 
	RenderObject* ro;
	RenderObject* secondRo;
	RenderObject* thirdRo;
	Controller* input;
};

