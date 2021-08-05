#pragma region Includes Traces Of Dog Shit
#include "gd.h"
#include "Layer.h"
#include "MenuLayer.h"
#include "CCDirectorModified.h"
#include "HackBools.h"
#include <cocos2d.h>
#include <GUI/CCControlExtension/CCScale9Sprite.h>
#include <thread>
#include "Speedhack.h"
#include "FPSBypass.h"
#pragma endregion

using namespace Vhacks;

int menuNumber = 1;
CCMenu* vMenu = nullptr;
CCMenu* coreMenu = nullptr;
CCMenu* creatorMenu = nullptr;
CCMenu* buttonMenu = nullptr;
gd::CCTextInputNode* speedhackInput = nullptr;
gd::CCTextInputNode* setFPSInput = nullptr;

#pragma region VHacks
void Vhacks::Callbacks::SpeedHackSetSpeed(CCObject*) {
	gd::CCTextInputNode* speedhackInput = (gd::CCTextInputNode*)vMenu->getChildren()->objectAtIndex(3);
	auto speed = (float)strtod(speedhackInput->getString(), NULL);
	Speedhack::SetSpeed(speed);
}

void Vhacks::Callbacks::SetFPSCap(CCObject*) {
	gd::CCTextInputNode* setFPSInput = (gd::CCTextInputNode*)vMenu->getChildren()->objectAtIndex(6);
	float fpscap = (float)strtod(setFPSInput->getString(), NULL);
	FPSBypass::SetFPS(fpscap);
}
#pragma endregion
#pragma region Core Hacks
void Vhacks::Callbacks::AnticheatButton(CCObject*) {
	anticheatEnabled = !anticheatEnabled;
	if (anticheatEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x202AAA), "\xEB\x2E", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15FC2E), "\xEB", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20D3B3), "\x90\x90\x90\x90\x90", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FF7A2), "\x90\x90", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x18B2B4), "\xB0\x01", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20C4E6), "\xE9\xD7\x00\x00\x00\x90", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FD557), "\xEB\x0C", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FD742), "\xC7\x87\xE0\x02\x00\x00\x01\x00\x00\x00\xC7\x87\xE4\x02\x00\x00\x00\x00\x00\x00\x90\x90\x90\x90\x90\x90", 26, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FD756), "\x90\x90\x90\x90\x90\x90", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FD79A), "\x90\x90\x90\x90\x90\x90", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FD7AF), "\x90\x90\x90\x90\x90\x90", 6, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x202AAA), "\x74\x2E", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15FC2E), "\x74", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20D3B3), "\xE8\x58\x04\x00\x00", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FF7A2), "\x74\x6E", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x18B2B4), "\x88\xD8", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20C4E6), "\x0F\x85\xD6\x00\x00\x00", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FD557), "\x74\x0C", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FD742), "\x80\xBF\xDD\x02\x00\x00\x00\x0F\x85\x0A\xFE\xFF\xFF\x80\xBF\x34\x05\x00\x00\x00\x0F\x84\xFD\xFD\xFF\xFF", 26, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FD756), "\x0F\x84\xFD\xFD\xFF\xFF", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FD79A), "\x0F\x84\xB9\xFD\xFF\xFF", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FD7AF), "\x0F\x85\xA4\xFD\xFF\xFF", 6, NULL);
	}
}

void Vhacks::Callbacks::NoclipButton(CCObject*) {
	noclipEnabled = !noclipEnabled;
	if (noclipEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A1DD), "\xeb\x37", 2, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A1DD), "\x8a\x80", 2, NULL);
	}
}

void Vhacks::Callbacks::IconBypassButton(CCObject*) {
	iconBypassEnabled = !iconBypassEnabled;
	if (iconBypassEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC50A8), "\xB0\x01\x90\x90\x90", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC54BA), "\xB0\x01\x90\x90\x90", 5, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC50A8), "\xE8\x7A\xCD\x19\x00", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC54BA), "\xE8\x68\xC9\x19\x00", 5, NULL);
	}
}

void Vhacks::Callbacks::AccuratePercentageButton(CCObject*) {
	accuratePercentageEnabled = !accuratePercentageEnabled;
	if (accuratePercentageEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2080FB), "\xFF\x50\x64\xF3\x0F\x10\x00\x8B\x87\xC0\x03\x00\x00\x83\xEC\x08\x42", 17, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x208114), "\xF3\x0F\x5E\x87\xB4\x03\x00\x00\xC7\x02\x25\x2E\x32\x66\xC7\x42\x04\x25\x25\x00\x00\x8B\xB0\x04\x01\x00\x00\xF3\x0F\x5A\xC0\xF2\x0F\x11\x04\x24\x52", 37, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20813F), "\x83\xC4\x0C", 3, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2080FB), "\xFF\x50\x64\xF3\x0F\x10\x00\x8B\x87\xC0\x03\x00\x00\x83\xEC\x08\x42", 17, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x208114), "\xF3\x0F\x5E\x87\xB4\x03\x00\x00\xC7\x02\x25\x2E\x30\x66\xC7\x42\x04\x25\x25\x00\x00\x8B\xB0\x04\x01\x00\x00\xF3\x0F\x5A\xC0\xF2\x0F\x11\x04\x24\x52", 37, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20813F), "\x83\xC4\x0C", 3, NULL);
	}
}

void Vhacks::Callbacks::NoProgressBarButton(CCObject*) {
	noProgressBarEnabled = !noProgressBarEnabled;
	if (noProgressBarEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FCE89), "\x0F\x57\xC0\x90\x90\x90", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FCF38), "\x0D", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FCF6B), "\x3F", 1, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FCE89), "\xF3\x0F\x10\x44\x24\x48", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FCF38), "\x05", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FCF6B), "\x00", 1, NULL);
	}
}

void Vhacks::Callbacks::PracticeMusicHackButton(CCObject*) {
	practiceMusicHackEnabled = !practiceMusicHackEnabled;
	if (practiceMusicHackEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20C925), "\x90\x90\x90\x90\x90\x90", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20D143), "\x90\x90", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A563), "\x90\x90", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A595), "\x90\x90", 2, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20C925), "\x0F\x85\xF7\x00\x00\x00", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20D143), "\x75\x41", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A563), "\x75\x3E", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A595), "\x75\x0C", 2, NULL);
	}
}

void Vhacks::Callbacks::PracticePulseButton(CCObject*) {
	practicePulseEnabled = !practicePulseEnabled;
	if (practicePulseEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x205536), "\x90\x90", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20555D), "\x90\x90", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20553E), "\xEB", 1, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x205536), "\x75\x08", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20555D), "\x75\x03", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20553E), "\x74", 1, NULL);
	}
}

void Vhacks::Callbacks::FreeWindowResizeButton(CCObject*) {
	freeWindowResizeEnabled = !freeWindowResizeEnabled;
	if (freeWindowResizeEnabled) {
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x11388B, "\xE8\xB0\xF3\xFF\xFF", 5);
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x11339D, "\xE8\xEE\xF6\xFF\xFF\x8B\xC8", 7);
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x1133C0, "\x50", 1);
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x1133C6, "\x50", 1);
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x112536, "\xEB\x11\x90", 3);
	}
	else {
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x11388B, "\x90\x90\x90\x90\x90", 5);
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x11339D, "\xB9\xFF\xFF\xFF\x7F\x90\x90", 7);
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x1133C0, "\x48", 1);
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x1133C6, "\x48", 1);
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x112536, "\x50\x6A\x00", 3);
	}
}

void Vhacks::Callbacks::SafeModeButton(CCObject*) {
	safeModeEnabled = !safeModeEnabled;
	if (safeModeEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A3B2), "\xE9\x9A\x01\x00\x00\x90\x90", 7, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FD40F), "\xE9\x13\x06\x00\x00\x90\x90", 7, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A3B2), "\x80\xBB\x94\x04\x00\x00\x00", 7, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FD40F), "\x83\xB9\x64\x03\x00\x00\x01", 7, NULL);
	}
}

void Vhacks::Callbacks::NoTransitionButton(CCObject*) {
	noTransitionEnabled = !noTransitionEnabled;
	if (noTransitionEnabled) {
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0xA5424, "\x90\x90\x90\x90\x90", 5);
	}
	else {
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0xA5424, "\xF3\x0F\x10\x45\x08", 5);
	}
}

void Vhacks::Callbacks::NoDeathEffectButton(CCObject*) {
	noDeathEffectEnabled = !noDeathEffectEnabled;
	if (noDeathEffectEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1EFBE0), "\xC3", 1, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1EFBE0), "\x55", 1, NULL);
	}
}

void Vhacks::Callbacks::NoRespawnBlinkButton(CCObject*) {
	noRespawnBlinkEnabled = !noRespawnBlinkEnabled;
	if (noRespawnBlinkEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1EF389), "\xC7\x04\x24\x00\x00\x00\x00", 7, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1EF389), "\xC7\x04\x24\xCD\xCC\xCC\x3E", 7, NULL);
	}
}

void Vhacks::Callbacks::NoRotationButton(CCObject*) {
	noRotationEnabled = !noRotationEnabled;
	if (noRotationEnabled) {
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x60554, "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90", 10);
	}
	else {
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x60554, "\xF3\x0F\x11\x49\x24\xF3\x0F\x11\x49\x20", 10);
	}
}

void Vhacks::Callbacks::ForceVisibilityButton(CCObject*) {
	forceVisibilityEnabled = !forceVisibilityEnabled;
	if (forceVisibilityEnabled) {
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x60753, "\xB0\x01\x90", 3);
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x60C5A, "\x90\x90\x90\x90\x90\x90", 6);
	}
	else {
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x60753, "\x8A\x45\x08", 3);
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x60C5A, "\x0F\x84\xCB\x00\x00\x00", 6);
	}
}

void Vhacks::Callbacks::TransparentMenuButton(CCObject*) {
	transparentMenuEnabled = !transparentMenuEnabled;
	if (transparentMenuEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17DEB0), "\x6A\x00\x90\x90\x90", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17E3BB), "\x6A\x30\x90\x90\x90", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17E8DD), "\x6A\x00\x90\x90\x90", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17EBB9), "\x6A\x00\x90\x90\x90", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17DF73), "\x6A\x00\x90\x90\x90", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x6F9BE), "\x6A\x00\x90\x90\x90", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x6FC49), "\x6A\x30\x90\x90\x90", 5, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17DEB0), "\x68\xFF\x00\x00\x00", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17E3BB), "\x68\xFF\x00\x00\x00", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17E8DD), "\x68\xFF\x00\x00\x00", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17EBB9), "\x68\xFF\x00\x00\x00", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17DF73), "\x68\xFF\x00\x00\x00", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x6F9BE), "\x68\xFF\x00\x00\x00", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x6FC49), "\x68\xFF\x00\x00\x00", 5, NULL);
	}
}

void Vhacks::Callbacks::TransparentBGButton(CCObject*) {
	transparentBGEnabled = !transparentBGEnabled;
	if (transparentBGEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15A174), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15A175), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15A16F), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15A16D), "\x90\xB1", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15891D), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15891E), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x158917), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x158915), "\x90\xB1", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x6F7FB), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x6F7FC), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x6F7F6), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x6F7F4), "\x90\xB1", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1979AD), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1979AE), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1979A7), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1979A5), "\x90\xB1", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17DBC1), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17DBC2), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17DBBB), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17DBB9), "\x90\xB1", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176032), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176033), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176036), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176034), "\x90\xB1", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x4DF7E), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x4DF7F), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x4DF78), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x4DF76), "\x90\xB1", 2, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15A174), "\x00", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15A175), "\x66", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15A16F), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15A16D), "\x80\xC9", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15891D), "\x00", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15891E), "\x66", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x158917), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x158915), "\x80\xC9", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x6F7FB), "\x00", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x6F7FC), "\x66", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x6F7F6), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x6F7F4), "\x80\xC9", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1979AD), "\x00", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1979AE), "\x66", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1979A7), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1979A5), "\x80\xC9", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17DBC1), "\x00", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17DBC2), "\x66", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17DBBB), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17DBB9), "\x80\xC9", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176032), "\x00", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176033), "\x66", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176036), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176034), "\x80\xC9", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x4DF7E), "\x00", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x4DF7F), "\x66", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x4DF78), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x4DF76), "\x80\xC9", 2, NULL);
	}
}

void Vhacks::Callbacks::TransparentListsButton(CCObject*) {
	transparentListsEnabled = !transparentListsEnabled;
	if (transparentListsEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15C02C), "\x00\x00\x00\x40", 4, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x5C70A), "\x60", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x5C6D9), "\x20\x20", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x5C6DC), "\x20", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x5C6CF), "\x40\x40", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x5C6D2), "\x40", 1, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15C02C), "\xBF\x72\x3E\xFF", 4, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x5C70A), "\xFF", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x5C6D9), "\xA1\x58", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x5C6DC), "\x2C", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x5C6CF), "\xC2\x72", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x5C6D2), "\x3E", 1, NULL);
	}
}
#pragma endregion
#pragma region Creator Hacks
void Vhacks::Callbacks::CopyHackButton(CCObject*) {
	copyHackEnabled = !copyHackEnabled;
	if (copyHackEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x179B8E), "\x90\x90", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176F5C), "\x8B\xCA\x90", 3, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176FE5), "\xB0\x01\x90", 3, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x179B8E), "\x75\x0E", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176F5C), "\x0F\x44\xCA", 3, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x176FE5), "\x0F\x95\xC0", 3, NULL);
	}
}

void Vhacks::Callbacks::LevelEditButton(CCObject*) {
	levelEditEnabled = !levelEditEnabled;
	if (levelEditEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1E4A32), "\x90\x90", 2, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1E4A32), "\x75\x6C", 2, NULL);
	}
}

void Vhacks::Callbacks::NoCMarkButton(CCObject*) {
	noCMarkEnabled = !noCMarkEnabled;
	if (noCMarkEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xA6B8B), "\x2B\x87\xCC\x02\x00\x00", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x70E87), "\xEB\x26", 2, NULL);
	}
	else {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xA6B8B), "\x2B\x87\xD0\x02\x00\x00", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x70E87), "\x74\x26", 2, NULL);
	}
}
#pragma endregion

// Changing Menus
#pragma region Menus
void Vhacks::Callbacks::SetMenu() {

	CCDirector* director = CCDirector::sharedDirector();
	auto winSize = director->getWinSize();

	if (menuNumber == 1) {
		vMenu->setPositionY(winSize.height - 50);

		coreMenu->setPositionY(-20000);
		creatorMenu->setPositionY(-20000);
	}
	if (menuNumber == 2) {
		coreMenu->setPositionY(winSize.height - 50);

		vMenu->setPositionY(-20000);
		creatorMenu->setPositionY(-20000);
	}
	if (menuNumber == 3) {
		creatorMenu->setPositionY(winSize.height - 50);

		vMenu->setPositionY(-20000);
		coreMenu->setPositionY(-20000);
	}
}

void Vhacks::Callbacks::LeftArrowPressed(CCObject*) {

	menuNumber -= 1;
	if (menuNumber < 1) menuNumber = 3;

	Vhacks::Callbacks::SetMenu();
}

void Vhacks::Callbacks::RightArrowPressed(CCObject*) {

	menuNumber += 1;
	if (menuNumber > 3) menuNumber = 1;

	Vhacks::Callbacks::SetMenu();
}
#pragma endregion

bool Layer::init() {
	// Setup
	#pragma region Setup Shit Here Lmao
	Vhacks::init();

	CCDirector* director = CCDirector::sharedDirector();
	auto winSize = director->getWinSize();

	this->setTag(0);

	auto label = CCLabelBMFont::create("VHacks", "goldFont.fnt");
	label->setPosition(winSize / 2);
	label->setPositionY(winSize.height - 20);
	label->setTag(1);
	#pragma endregion
	#pragma region Some Stupid Shit Like Side Buttons Or Whatever
	auto toggleOn = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
	auto toggleOff = CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");

	auto leftArrowSprite = CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png");
	auto rightArrowSprite = CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png");

	auto leftArrowButton = gd::CCMenuItemSpriteExtra::create(leftArrowSprite, buttonMenu, (cocos2d::SEL_MenuHandler)&Vhacks::Callbacks::LeftArrowPressed);
	auto rightArrowButton = gd::CCMenuItemSpriteExtra::create(rightArrowSprite, buttonMenu, (cocos2d::SEL_MenuHandler)&Vhacks::Callbacks::RightArrowPressed);

	rightArrowButton->setRotationY(180);
	leftArrowButton->setPositionX(15);
	leftArrowButton->setPositionY(winSize.height / 2);
	rightArrowButton->setPositionX(winSize.width - 15);
	rightArrowButton->setPositionY(winSize.height / 2);

	buttonMenu->addChild(leftArrowButton);
	buttonMenu->addChild(rightArrowButton);
	#pragma endregion

	//Buttons and Text
	#pragma region VHacks

	auto speedhackText = CCLabelBMFont::create("Speedhack", "bigFont-uhd.fnt");
	auto speedhackInput = gd::CCTextInputNode::create("Speed", vMenu, "bigFont-uhd.fnt", 50, 30);
	auto speedhackInputBG = extension::CCScale9Sprite::create("square02_small.png");
	auto speedhackSetSpeedSprite = CCSprite::create("VHacksSetSpeed.png");
	auto speedhackSetSpeedButton = gd::CCMenuItemSpriteExtra::create(speedhackSetSpeedSprite, vMenu, menu_selector(Vhacks::Callbacks::SpeedHackSetSpeed));
	speedhackText->setTag(2);
	speedhackText->setScale(0.5f);
	speedhackText->setPositionX(speedhackText->getScaledContentSize().width / 2);
	speedhackInput->setScale(0.5f);
	speedhackInput->setAllowedChars("1234567890.");
	speedhackInput->setMaxLabelLength(5);
	speedhackInput->setPositionX(25 + speedhackText->getScaledContentSize().width);
	speedhackInput->setPositionY(0 - speedhackText->getScaledContentSize().height / 2);
	speedhackInput->setLabelPlaceholderColor({ 120, 171, 240 });
	speedhackInputBG->setScale(0.7);
	speedhackInputBG->setScaleX(1.3);
	speedhackInputBG->setOpacity(90);
	speedhackInputBG->setZOrder(-1);
	speedhackInputBG->setPositionX(126);
	speedhackSetSpeedButton->setPositionX(151 + speedhackSetSpeedButton->getScaledContentSize().width / 2);
	speedhackSetSpeedSprite->setScale(0.7f);

	vMenu->addChild(speedhackText);
	vMenu->addChild(speedhackInput);
	vMenu->addChild(speedhackInputBG);
	vMenu->addChild(speedhackSetSpeedButton);

	auto setFPSText = CCLabelBMFont::create("FPS Bypass", "bigFont-uhd.fnt");
	auto setFPSInput = gd::CCTextInputNode::create("FPS", vMenu, "bigFont-uhd.fnt", 50, 30);
	auto setFPSInputBG = extension::CCScale9Sprite::create("square02_small.png");
	auto setFPSCapSprite = CCSprite::create("VHacksSetFPS.png");
	auto setFPSCapButton = gd::CCMenuItemSpriteExtra::create(setFPSCapSprite, vMenu, menu_selector(Vhacks::Callbacks::SetFPSCap));
	setFPSText->setTag(2);
	setFPSText->setScale(0.5f);
	setFPSText->setPositionX(setFPSText->getScaledContentSize().width / 2);
	setFPSText->setPositionY(-35);
	setFPSInput->setScale(0.5f);
	setFPSInput->setAllowedChars("1234567890");
	setFPSInput->setMaxLabelLength(5);
	setFPSInput->setPositionX(114.625);
	setFPSInput->setPositionY(-35 - setFPSText->getScaledContentSize().height / 2);
	setFPSInput->setLabelPlaceholderColor({ 120, 171, 240 });
	setFPSInputBG->setScale(0.7);
	setFPSInputBG->setScaleX(1.3);
	setFPSInputBG->setOpacity(90);
	setFPSInputBG->setZOrder(-1);
	setFPSInputBG->setPositionX(126);
	setFPSInputBG->setPositionY(-35);
	setFPSCapButton->setPositionX(151 + setFPSCapButton->getScaledContentSize().width / 2);
	setFPSCapButton->setPositionY(-35);
	setFPSCapSprite->setScale(0.7f);
	
	vMenu->addChild(setFPSText);
	vMenu->addChild(setFPSInput);
	vMenu->addChild(setFPSInputBG);
	vMenu->addChild(setFPSCapButton);
#pragma endregion
	#pragma region Core Hacks
	auto anticheatButton = gd::CCMenuItemToggler::create((anticheatEnabled) ? toggleOn : toggleOff, (anticheatEnabled) ? toggleOff : toggleOn, coreMenu, menu_selector(Vhacks::Callbacks::AnticheatButton));
	auto anticheatText = CCLabelBMFont::create("Anticheat", "bigFont-uhd.fnt");
	anticheatText->setTag(2);
	anticheatButton->setScale(0.8f);
	anticheatText->setScale(0.5f);
	anticheatButton->setPositionX(0);
	anticheatText->setPositionX(25 + (anticheatText->getScaledContentSize().width / 2));
	anticheatButton->setPositionY(0);
	anticheatText->setPositionY(0);
	coreMenu->addChild(anticheatButton);
	coreMenu->addChild(anticheatText);

	auto noclipButton = gd::CCMenuItemToggler::create((noclipEnabled) ? toggleOn : toggleOff, (noclipEnabled) ? toggleOff : toggleOn, coreMenu, menu_selector(Vhacks::Callbacks::NoclipButton));
	auto noclipText = CCLabelBMFont::create("Noclip", "bigFont-uhd.fnt");
	noclipText->setTag(2);
	noclipButton->setScale(0.8f);
	noclipText->setScale(0.5f);
	noclipButton->setPositionX(0);
	noclipText->setPositionX(25 + (noclipText->getScaledContentSize().width / 2));
	noclipButton->setPositionY(-30);
	noclipText->setPositionY(-30);
	coreMenu->addChild(noclipButton);
	coreMenu->addChild(noclipText);

	auto iconBypassButton = gd::CCMenuItemToggler::create((iconBypassEnabled) ? toggleOn : toggleOff, (iconBypassEnabled) ? toggleOff : toggleOn, coreMenu, menu_selector(Vhacks::Callbacks::IconBypassButton));
	auto iconBypassText = CCLabelBMFont::create("Icon Bypass", "bigFont-uhd.fnt");
	iconBypassText->setTag(2);
	iconBypassButton->setScale(0.8f);
	iconBypassText->setScale(0.5f);
	iconBypassButton->setPositionX(0);
	iconBypassText->setPositionX(25 + (iconBypassText->getScaledContentSize().width / 2));
	iconBypassButton->setPositionY(-60);
	iconBypassText->setPositionY(-60);
	coreMenu->addChild(iconBypassButton);
	coreMenu->addChild(iconBypassText);

	auto accuratePercentageButton = gd::CCMenuItemToggler::create((accuratePercentageEnabled) ? toggleOn : toggleOff, (accuratePercentageEnabled) ? toggleOff : toggleOn, coreMenu, menu_selector(Vhacks::Callbacks::AccuratePercentageButton));
	auto accuratePercentageText = CCLabelBMFont::create("Accurate Percentage", "bigFont-uhd.fnt");
	accuratePercentageText->setTag(2);
	accuratePercentageButton->setScale(0.8f);
	accuratePercentageText->setScale(0.5f);
	accuratePercentageButton->setPositionX(0);
	accuratePercentageText->setPositionX(25 + (accuratePercentageText->getScaledContentSize().width / 2));
	accuratePercentageButton->setPositionY(-90);
	accuratePercentageText->setPositionY(-90);
	coreMenu->addChild(accuratePercentageButton);
	coreMenu->addChild(accuratePercentageText);

	auto noProgressBarButton = gd::CCMenuItemToggler::create((noProgressBarEnabled) ? toggleOn : toggleOff, (noProgressBarEnabled) ? toggleOff : toggleOn, coreMenu, menu_selector(Vhacks::Callbacks::NoProgressBarButton));
	auto noProgressBarText = CCLabelBMFont::create("No Progress Bar", "bigFont-uhd.fnt");
	noProgressBarText->setTag(2);
	noProgressBarButton->setScale(0.8f);
	noProgressBarText->setScale(0.5f);
	noProgressBarButton->setPositionX(0);
	noProgressBarText->setPositionX(25 + (noProgressBarText->getScaledContentSize().width / 2));
	noProgressBarButton->setPositionY(-120);
	noProgressBarText->setPositionY(-120);
	coreMenu->addChild(noProgressBarButton);
	coreMenu->addChild(noProgressBarText);

	auto practiceMusicHackButton = gd::CCMenuItemToggler::create((practiceMusicHackEnabled) ? toggleOn : toggleOff, (practiceMusicHackEnabled) ? toggleOff : toggleOn, coreMenu, menu_selector(Vhacks::Callbacks::PracticeMusicHackButton));
	auto practiceMusicHackText = CCLabelBMFont::create("Practice Music Hack", "bigFont-uhd.fnt");
	practiceMusicHackText->setTag(2);
	practiceMusicHackButton->setScale(0.8f);
	practiceMusicHackText->setScale(0.5f);
	practiceMusicHackButton->setPositionX(0);
	practiceMusicHackText->setPositionX(25 + (practiceMusicHackText->getScaledContentSize().width / 2));
	practiceMusicHackButton->setPositionY(-150);
	practiceMusicHackText->setPositionY(-150);
	coreMenu->addChild(practiceMusicHackButton);
	coreMenu->addChild(practiceMusicHackText);

	auto practicePulseButton = gd::CCMenuItemToggler::create((practicePulseEnabled) ? toggleOn : toggleOff, (practicePulseEnabled) ? toggleOff : toggleOn, coreMenu, menu_selector(Vhacks::Callbacks::PracticePulseButton));
	auto practicePulseText = CCLabelBMFont::create("Practice Pulse", "bigFont-uhd.fnt");
	practicePulseText->setTag(2);
	practicePulseButton->setScale(0.8f);
	practicePulseText->setScale(0.5f);
	practicePulseButton->setPositionX(0);
	practicePulseText->setPositionX(25 + (practicePulseText->getScaledContentSize().width / 2));
	practicePulseButton->setPositionY(-180);
	practicePulseText->setPositionY(-180);
	coreMenu->addChild(practicePulseButton);
	coreMenu->addChild(practicePulseText);

	auto freeWindowResizeButton = gd::CCMenuItemToggler::create((freeWindowResizeEnabled) ? toggleOn : toggleOff, (freeWindowResizeEnabled) ? toggleOff : toggleOn, coreMenu, menu_selector(Vhacks::Callbacks::FreeWindowResizeButton));
	auto freeWindowResizeText = CCLabelBMFont::create("Free Window Resize", "bigFont-uhd.fnt");
	freeWindowResizeText->setTag(2);
	freeWindowResizeButton->setScale(0.8f);
	freeWindowResizeText->setScale(0.5f);
	freeWindowResizeButton->setPositionX(0);
	freeWindowResizeText->setPositionX(25 + (freeWindowResizeText->getScaledContentSize().width / 2));
	freeWindowResizeButton->setPositionY(-210);
	freeWindowResizeText->setPositionY(-210);
	coreMenu->addChild(freeWindowResizeButton);
	coreMenu->addChild(freeWindowResizeText);

	auto safeModeButton = gd::CCMenuItemToggler::create((safeModeEnabled) ? toggleOn : toggleOff, (safeModeEnabled) ? toggleOff : toggleOn, coreMenu, menu_selector(Vhacks::Callbacks::SafeModeButton));
	auto safeModeText = CCLabelBMFont::create("Safe Mode", "bigFont-uhd.fnt");
	safeModeText->setTag(2);
	safeModeButton->setScale(0.8f);
	safeModeText->setScale(0.5f);
	safeModeButton->setPositionX(0);
	safeModeText->setPositionX(25 + (safeModeText->getScaledContentSize().width / 2));
	safeModeButton->setPositionY(-240);
	safeModeText->setPositionY(-240);
	coreMenu->addChild(safeModeButton);
	coreMenu->addChild(safeModeText);

	auto noTransitionButton = gd::CCMenuItemToggler::create((noTransitionEnabled) ? toggleOn : toggleOff, (noTransitionEnabled) ? toggleOff : toggleOn, coreMenu, menu_selector(Vhacks::Callbacks::NoTransitionButton));
	auto noTransitionText = CCLabelBMFont::create("No Transition", "bigFont-uhd.fnt");
	noTransitionText->setTag(2);
	noTransitionButton->setScale(0.8f);
	noTransitionText->setScale(0.5f);
	noTransitionButton->setPositionX(235);
	noTransitionText->setPositionX(235 + 25 + (noTransitionText->getScaledContentSize().width / 2));
	noTransitionButton->setPositionY(0);
	noTransitionText->setPositionY(0);
	coreMenu->addChild(noTransitionButton);
	coreMenu->addChild(noTransitionText);

	auto noDeathEffectButton = gd::CCMenuItemToggler::create((noDeathEffectEnabled) ? toggleOn : toggleOff, (noDeathEffectEnabled) ? toggleOff : toggleOn, coreMenu, menu_selector(Vhacks::Callbacks::NoDeathEffectButton));
	auto noDeathEffectText = CCLabelBMFont::create("No Death Effect", "bigFont-uhd.fnt");
	noDeathEffectText->setTag(2);
	noDeathEffectButton->setScale(0.8f);
	noDeathEffectText->setScale(0.5f);
	noDeathEffectButton->setPositionX(235);
	noDeathEffectText->setPositionX(235 + 25 + (noDeathEffectText->getScaledContentSize().width / 2));
	noDeathEffectButton->setPositionY(-30);
	noDeathEffectText->setPositionY(-30);
	coreMenu->addChild(noDeathEffectButton);
	coreMenu->addChild(noDeathEffectText);

	auto noRespawnBlinkButton = gd::CCMenuItemToggler::create((noRespawnBlinkEnabled) ? toggleOn : toggleOff, (noRespawnBlinkEnabled) ? toggleOff : toggleOn, coreMenu, menu_selector(Vhacks::Callbacks::NoRespawnBlinkButton));
	auto noRespawnBlinkText = CCLabelBMFont::create("No Respawn Blink", "bigFont-uhd.fnt");
	noRespawnBlinkText->setTag(2);
	noRespawnBlinkButton->setScale(0.8f);
	noRespawnBlinkText->setScale(0.5f);
	noRespawnBlinkButton->setPositionX(235);
	noRespawnBlinkText->setPositionX(235 + 25 + (noRespawnBlinkText->getScaledContentSize().width / 2));
	noRespawnBlinkButton->setPositionY(-60);
	noRespawnBlinkText->setPositionY(-60);
	coreMenu->addChild(noRespawnBlinkButton);
	coreMenu->addChild(noRespawnBlinkText);

	auto noRotationButton = gd::CCMenuItemToggler::create((noRotationEnabled) ? toggleOn : toggleOff, (noRotationEnabled) ? toggleOff : toggleOn, coreMenu, menu_selector(Vhacks::Callbacks::NoRotationButton));
	auto noRotationText = CCLabelBMFont::create("No Rotation", "bigFont-uhd.fnt");
	noRotationText->setTag(2);
	noRotationButton->setScale(0.8f);
	noRotationText->setScale(0.5f);
	noRotationButton->setPositionX(235);
	noRotationText->setPositionX(235 + 25 + (noRotationText->getScaledContentSize().width / 2));
	noRotationButton->setPositionY(-90);
	noRotationText->setPositionY(-90);
	coreMenu->addChild(noRotationButton);
	coreMenu->addChild(noRotationText);

	auto forceVisibilityButton = gd::CCMenuItemToggler::create((forceVisibilityEnabled) ? toggleOn : toggleOff, (forceVisibilityEnabled) ? toggleOff : toggleOn, coreMenu, menu_selector(Vhacks::Callbacks::ForceVisibilityButton));
	auto forceVisibilityText = CCLabelBMFont::create("Force Visibility", "bigFont-uhd.fnt");
	forceVisibilityText->setTag(2);
	forceVisibilityButton->setScale(0.8f);
	forceVisibilityText->setScale(0.5f);
	forceVisibilityButton->setPositionX(235);
	forceVisibilityText->setPositionX(235 + 25 + (forceVisibilityText->getScaledContentSize().width / 2));
	forceVisibilityButton->setPositionY(-120);
	forceVisibilityText->setPositionY(-120);
	coreMenu->addChild(forceVisibilityButton);
	coreMenu->addChild(forceVisibilityText);

	auto transparentMenuButton = gd::CCMenuItemToggler::create((transparentMenuEnabled) ? toggleOn : toggleOff, (transparentMenuEnabled) ? toggleOff : toggleOn, coreMenu, menu_selector(Vhacks::Callbacks::TransparentMenuButton));
	auto transparentMenuText = CCLabelBMFont::create("Transparent Menu", "bigFont-uhd.fnt");
	transparentMenuText->setTag(2);
	transparentMenuButton->setScale(0.8f);
	transparentMenuText->setScale(0.5f);
	transparentMenuButton->setPositionX(235);
	transparentMenuText->setPositionX(235 + 25 + (transparentMenuText->getScaledContentSize().width / 2));
	transparentMenuButton->setPositionY(-150);
	transparentMenuText->setPositionY(-150);
	coreMenu->addChild(transparentMenuButton);
	coreMenu->addChild(transparentMenuText);

	auto transparentBGButton = gd::CCMenuItemToggler::create((transparentBGEnabled) ? toggleOn : toggleOff, (transparentBGEnabled) ? toggleOff : toggleOn, coreMenu, menu_selector(Vhacks::Callbacks::TransparentBGButton));
	auto transparentBGText = CCLabelBMFont::create("Transparent BG", "bigFont-uhd.fnt");
	transparentBGText->setTag(2);
	transparentBGButton->setScale(0.8f);
	transparentBGText->setScale(0.5f);
	transparentBGButton->setPositionX(235);
	transparentBGText->setPositionX(235 + 25 + (transparentBGText->getScaledContentSize().width / 2));
	transparentBGButton->setPositionY(-180);
	transparentBGText->setPositionY(-180);
	coreMenu->addChild(transparentBGButton);
	coreMenu->addChild(transparentBGText);

	auto transparentListsButton = gd::CCMenuItemToggler::create((transparentListsEnabled) ? toggleOn : toggleOff, (transparentListsEnabled) ? toggleOff : toggleOn, coreMenu, menu_selector(Vhacks::Callbacks::TransparentListsButton));
	auto transparentListsText = CCLabelBMFont::create("Transparent Lists", "bigFont-uhd.fnt");
	transparentListsText->setTag(2);
	transparentListsButton->setScale(0.8f);
	transparentListsText->setScale(0.5f);
	transparentListsButton->setPositionX(235);
	transparentListsText->setPositionX(235 + 25 + (transparentListsText->getScaledContentSize().width / 2));
	transparentListsButton->setPositionY(-210);
	transparentListsText->setPositionY(-210);
	coreMenu->addChild(transparentListsButton);
	coreMenu->addChild(transparentListsText);
	#pragma endregion
	#pragma region Creator Hacks

	auto copyHackButton = gd::CCMenuItemToggler::create((copyHackEnabled) ? toggleOn : toggleOff, (copyHackEnabled) ? toggleOff : toggleOn, creatorMenu, menu_selector(Vhacks::Callbacks::CopyHackButton));
	auto copyHackText = CCLabelBMFont::create("Copy Hack", "bigFont-uhd.fnt");
	copyHackText->setTag(2);
	copyHackButton->setScale(0.8f);
	copyHackText->setScale(0.5f);
	copyHackButton->setPositionX(0);
	copyHackText->setPositionX(25 + (copyHackText->getScaledContentSize().width / 2));
	copyHackButton->setPositionY(0);
	copyHackText->setPositionY(0);
	creatorMenu->addChild(copyHackButton);
	creatorMenu->addChild(copyHackText);

	auto levelEditButton = gd::CCMenuItemToggler::create((levelEditEnabled) ? toggleOn : toggleOff, (levelEditEnabled) ? toggleOff : toggleOn, creatorMenu, menu_selector(Vhacks::Callbacks::LevelEditButton));
	auto levelEditText = CCLabelBMFont::create("Level Edit", "bigFont-uhd.fnt");
	levelEditText->setTag(2);
	levelEditButton->setScale(0.8f);
	levelEditText->setScale(0.5f);
	levelEditButton->setPositionX(0);
	levelEditText->setPositionX(25 + (levelEditText->getScaledContentSize().width / 2));
	levelEditButton->setPositionY(-30);
	levelEditText->setPositionY(-30);
	creatorMenu->addChild(levelEditButton);
	creatorMenu->addChild(levelEditText);
	
	auto noCMarkButton = gd::CCMenuItemToggler::create((noCMarkEnabled) ? toggleOn : toggleOff, (noCMarkEnabled) ? toggleOff : toggleOn, creatorMenu, menu_selector(Vhacks::Callbacks::NoCMarkButton));
	auto noCMarkText = CCLabelBMFont::create("No C Mark", "bigFont-uhd.fnt");
	noCMarkText->setTag(2);
	noCMarkButton->setScale(0.8f);
	noCMarkText->setScale(0.5f);
	noCMarkButton->setPositionX(0);
	noCMarkText->setPositionX(25 + (noCMarkText->getScaledContentSize().width / 2));
	noCMarkButton->setPositionY(-60);
	noCMarkText->setPositionY(-60);
	creatorMenu->addChild(noCMarkButton);
	creatorMenu->addChild(noCMarkText);

	#pragma endregion


	// Other Stuff
	#pragma region Add Children Here AKA The Basement

	addChild(buttonMenu, 3);
	addChild(vMenu, 2);
	addChild(coreMenu, 2);
	addChild(creatorMenu, 2);
	addChild(label);
	#pragma endregion
	#pragma region More Shit That I Dont Have To Worry About Lol
	auto topLeft = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
	auto bottomLeft = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
	auto topRight = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");
	auto bottomRight = CCSprite::createWithSpriteFrameName("GJ_sideArt_001.png");

	topLeft->setFlipY(true);
	topRight->setFlipY(true);
	topRight->setFlipX(true);
	bottomRight->setFlipX(true);

	CCSize size = bottomLeft->getScaledContentSize();

	bottomLeft->setPosition({ size.width / 2, size.height / 2 });

	topLeft->setPosition({ size.width / 2, (winSize.height) - (size.height / 2) });

	topRight->setPosition({ (winSize.width) - (size.width / 2), (winSize.height) - (size.height / 2) });

	bottomRight->setPosition({ (winSize.width) - (size.width / 2), size.height / 2 });

	addChild(topLeft, 1);
	addChild(bottomLeft, 1);
	addChild(topRight, 1);
	addChild(bottomRight, 1);

	this->setKeypadEnabled(true);

	CCScene* wrapperScene = CCScene::create();

	wrapperScene->addChild(this);

	auto transition = CCTransitionFade::create(0.5f, wrapperScene);

	return director->pushScene(transition);
	#pragma endregion
}

// Other Other Stuff
#pragma region Key Back Clicked
void Layer::keyBackClicked(void) {
	Layer::returnToMenu(nullptr);
}
#pragma endregion
#pragma region Return To Menu
void Layer::returnToMenu(CCObject* pSender) {
	CCDirectorModified* director = (CCDirectorModified*)CCDirectorModified::sharedDirector();

	director->replaceScene(
		CCTransitionFade::create(0.5f, director->getPreviousScene())
	);
}
#pragma endregion
#pragma region Create Layer Thing
Layer* Layer::create() {
	Layer* l = new Layer();
	l->initWithColor({ 0, 101, 253, 255 }, { 0, 46, 115, 255 });
	//l->init();
	if (l && l->init()) {
		l->autorelease();
		return l;
	}
	else {
		CC_SAFE_DELETE(l);
		return NULL;
	}
}
#pragma endregion