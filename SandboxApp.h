#pragma once
#include "Application/YorkiEngineApp.h"

class RenderObject;
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
	RenderObject* ro;
	RenderObject* secondRo;
	RenderObject* thirdRo;
	Input* input;
};

