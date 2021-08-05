#pragma once
#include "gd.h"
#include "HackBools.h"
#include "Layer.h"

static void SetActive() {

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
	if (noclipEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A1DD), "\xeb\x37", 2, NULL);
	}
	if (iconBypassEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC50A8), "\xB0\x01\x90\x90\x90", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0xC54BA), "\xB0\x01\x90\x90\x90", 5, NULL);
	}
	if (accuratePercentageEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x2080FB), "\xFF\x50\x64\xF3\x0F\x10\x00\x8B\x87\xC0\x03\x00\x00\x83\xEC\x08\x42", 17, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x208114), "\xF3\x0F\x5E\x87\xB4\x03\x00\x00\xC7\x02\x25\x2E\x32\x66\xC7\x42\x04\x25\x25\x00\x00\x8B\xB0\x04\x01\x00\x00\xF3\x0F\x5A\xC0\xF2\x0F\x11\x04\x24\x52", 37, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20813F), "\x83\xC4\x0C", 3, NULL);
	}
	if (noProgressBarEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FCE89), "\x0F\x57\xC0\x90\x90\x90", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FCF38), "\x0D", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FCF6B), "\x3F", 1, NULL);
	}
	if (practiceMusicHackEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20C925), "\x90\x90\x90\x90\x90\x90", 6, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20D143), "\x90\x90", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A563), "\x90\x90", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A595), "\x90\x90", 2, NULL);
	}
	if (practicePulseEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x205536), "\x90\x90", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20555D), "\x90\x90", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20553E), "\xEB", 1, NULL);
	}
	if (freeWindowResizeEnabled) {
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x11388B, "\x90\x90\x90\x90\x90", 5);
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x11339D, "\xB9\xFF\xFF\xFF\x7F\x90\x90", 7);
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x1133C0, "\x48", 1);
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x1133C6, "\x48", 1);
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x112536, "\xEB\x11\x90", 3);
	}
	if (safeModeEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x20A3B2), "\xE9\x9A\x01\x00\x00\x90\x90", 7, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1FD40F), "\x80\xBB\x94\x04\x00\x00\x00", 7, NULL);
	}
	if (noTransitionEnabled) {
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0xA5424, "\x90\x90\x90\x90\x90", 5);
	}
	if (noDeathEffectEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1EFBE0), "\xC3", 1, NULL);
	}
	if (noRespawnBlinkEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x1EF389), "\xC7\x04\x24\x00\x00\x00\x00", 7, NULL);
	}
	if (noRotationEnabled) {
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x60554, "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90", 10);
	}
	if (forceVisibilityEnabled) {
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x60753, "\xB0\x01\x90", 3);
		Vhacks::Callbacks::WriteProcessMemoryModule("libcocos2d.dll", 0x60C5A, "\x90\x90\x90\x90\x90\x90", 6);
	}
	if (transparentMenuEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17DEB0), "\x6A\x00\x90\x90\x90", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17E3BB), "\x6A\x30\x90\x90\x90", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17E8DD), "\x6A\x00\x90\x90\x90", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17EBB9), "\x6A\x00\x90\x90\x90", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x17DF73), "\x6A\x00\x90\x90\x90", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x6F9BE), "\x6A\x00\x90\x90\x90", 5, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x6FC49), "\x6A\x30\x90\x90\x90", 5, NULL);
	}
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
	if (transparentListsEnabled) {
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x15C02C), "\x00\x00\x00\x40", 4, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x5C70A), "\x60", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x5C6D9), "\x20\x20", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x5C6DC), "\x20", 1, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x5C6CF), "\x40\x40", 2, NULL);
		WriteProcessMemory(GetCurrentProcess(), reinterpret_cast<void*>(gd::base + 0x5C6D2), "\x40", 1, NULL);
	}
}