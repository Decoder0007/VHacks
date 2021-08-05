// dllmain.cpp : Defines the entry point for the DLL application.
#include <cocos2d.h>
#include "MinHook.h"
#include "MenuLayer.h"
#include "Startup.h"
#include "Layer.h"
#include "Speedhack.h"
#include <thread>

DWORD WINAPI Main_Thread(void* hModule) {

    MH_Initialize();
    Speedhack::Setup();
    MenuLayer::mem_init();
    SetActive();
    MH_EnableHook(MH_ALL_HOOKS);

    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0x1000, Main_Thread, hModule, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

