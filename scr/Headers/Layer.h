#pragma once
#include <cocos2d.h>

using namespace cocos2d;

class Layer : public CCLayerGradient {
	Layer() = default;
	bool init();

	virtual void keyBackClicked(void);
public:
	static Layer* create();
	void returnToMenu(CCObject* sender);
};

extern int menuNumber;
extern cocos2d::CCMenu* vMenu;
extern cocos2d::CCMenu* coreMenu;
extern cocos2d::CCMenu* creatorMenu;
extern cocos2d::CCMenu* buttonMenu;
extern gd::CCTextInputNode* speedhackInput;
extern gd::CCTextInputNode* setFPSInput;

namespace Vhacks {

	inline void init() {
		CCDirector* director = CCDirector::sharedDirector();
		auto winSize = director->getWinSize();

		vMenu = CCMenu::create();
		vMenu->setPositionX(50);
		vMenu->setPositionY(winSize.height - 50);

		vMenu->setTag(3);

		coreMenu = CCMenu::create();
		coreMenu->setPositionX(50);
		coreMenu->setPositionY(-20000);

		coreMenu->setTag(3);

		creatorMenu = CCMenu::create();
		creatorMenu->setPositionX(50);
		creatorMenu->setPositionY(-20000);

		creatorMenu->setTag(3);

		buttonMenu = CCMenu::create();
		buttonMenu->setPositionX(0);
		buttonMenu->setPositionY(0);

		buttonMenu->setTag(3);

		menuNumber = 1;
	}

	class Callbacks {
	public:
		static void WriteProcessMemoryModule(LPCSTR module, int address, const void* bytes, int size) {
			DWORD old_prot;
			VirtualProtect(reinterpret_cast<void*>((DWORD)GetModuleHandleA(module) + address), size, PAGE_EXECUTE_READWRITE, &old_prot);
			memcpy(reinterpret_cast<void*>((DWORD)GetModuleHandleA(module) + address), bytes, size);
			VirtualProtect(reinterpret_cast<void*>((DWORD)GetModuleHandleA(module) + address), size, old_prot, &old_prot);
		}
		// Vhacks
		void SpeedHackSetSpeed(CCObject*);
		void SetFPSCap(CCObject*);
		
		// Core Hacks
		void AnticheatButton(CCObject*);
		void NoclipButton(CCObject*);
		void IconBypassButton(CCObject*);
		void AccuratePercentageButton(CCObject*);
		void NoProgressBarButton(CCObject*);
		void PracticeMusicHackButton(CCObject*);
		void PracticePulseButton(CCObject*);
		void FreeWindowResizeButton(CCObject*);
		void SafeModeButton(CCObject*);
		void NoTransitionButton(CCObject*);
		void NoDeathEffectButton(CCObject*);
		void NoRespawnBlinkButton(CCObject*);
		void NoRotationButton(CCObject*);
		void ForceVisibilityButton(CCObject*);
		void TransparentMenuButton(CCObject*);
		void TransparentBGButton(CCObject*);
		void TransparentListsButton(CCObject*);

		// Creator Hacks
		void CopyHackButton(CCObject*);
		void LevelEditButton(CCObject*);
		void NoCMarkButton(CCObject*);
		

		// Bypass Hacks

		// Player Hacks

		// Menu Stuff
		void LeftArrowPressed(CCObject*);
		void RightArrowPressed(CCObject*);
		void SetMenu();

	};
}