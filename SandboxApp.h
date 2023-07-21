#pragma once
#include "Application/YorkiEngineApp.h"

class SandboxApp : public YorkiEngineApp
{
public:
	SandboxApp();

protected:
	virtual void OnCreateApplication() override;
	virtual void OnPreDraw() override;
	virtual void OnPostDraw() override;
};

