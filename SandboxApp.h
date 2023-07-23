#pragma once
#include "Application/YorkiEngineApp.h"

class SandboxApp : public YorkiEngineApp
{
public:
	SandboxApp();

protected:
	virtual void OnCreateApplicationCallback() override;
	virtual void OnPreDraw() override;
	virtual void OnPostDraw() override;
};

