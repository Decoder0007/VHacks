#include "FPSBypass.h"
#include <windows.h>
#include <iostream>

fSharedApplication sharedApplication;
fSetAnimationInterval setAnimInterval;
float interval = 0;

void FPSBypass::SetFPS(int FPS) {
	interval = 1.0f / FPS;

	HMODULE hMod = LoadLibrary(L"libcocos2d.dll");
	sharedApplication = (fSharedApplication)GetProcAddress(hMod, "?sharedApplication@CCApplication@cocos2d@@SAPAV12@XZ");
	setAnimInterval = (fSetAnimationInterval)GetProcAddress(hMod, "?setAnimationInterval@CCApplication@cocos2d@@UAEXN@Z");

	void* application = sharedApplication();

	setAnimInterval(application, interval);
}