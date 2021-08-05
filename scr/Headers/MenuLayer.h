#pragma once
#include <cocos2d.h>
#include "MinHook.h"
#include "gd.h"

using namespace cocos2d;

namespace MenuLayer {

    inline bool(__thiscall* init)(CCLayer* self);
    bool __fastcall initHook(CCLayer* self);

    void mem_init();
}


class MoveToNewLayerBtnMenuLayer : public gd::CCMenuItemSpriteExtra {
public:
    void callback(CCObject* pSender);
};