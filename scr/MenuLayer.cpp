#include "MenuLayer.h"
#include "Layer.h"
#include "MinHook.h"
#include <Windows.h>
#include <thread>
#include "gd.h"
#include "HackBools.h"

using namespace Vhacks;

void MoveToNewLayerBtnMenuLayer::callback(CCObject* pSender) {
	Layer* layer = Layer::create();
	gd::CCMenuItemSpriteExtra* btn = (gd::CCMenuItemSpriteExtra*)pSender;
	btn->stopAllActions();
	btn->setScale(1.1);
}

bool __fastcall MenuLayer::initHook(CCLayer* self) {

	CCSprite* sprite = CCSprite::create("VHacksButton.png");

	auto btn = MoveToNewLayerBtnMenuLayer::create(sprite, self, menu_selector(MoveToNewLayerBtnMenuLayer::callback));

	btn->setScale(1.1);

	bool result = MenuLayer::init(self);

	auto children = self->getChildren();

	CCMenu* bottomMenu = (CCMenu*)children->objectAtIndex(3);

	bottomMenu->addChild(btn, 500);

	CCMenuItem* chestBtn = (CCMenuItem*)(bottomMenu->getChildren()->objectAtIndex(4));

	bottomMenu->removeChild(chestBtn, false);
	
	bottomMenu->alignItemsHorizontallyWithPadding(5.0f);

	bottomMenu->addChild(chestBtn);

	return result;
}

void MenuLayer::mem_init() {
	size_t base = reinterpret_cast<size_t>(GetModuleHandle(0));
	MH_CreateHook(
		(PVOID)(base + 0x1907b0),
		MenuLayer::initHook,
		(LPVOID*)&MenuLayer::init);
}