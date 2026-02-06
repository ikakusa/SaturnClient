#pragma once

#include "../HookManager.h"

namespace LocalPlayerHook {
    class normalTick : public HookClass {
    private:
        static inline std::unique_ptr<HookData> hookData;
        static inline uintptr_t address = MemUtils::find_signature("48 8B C4 48 89 58 10 48 89 70 18 48 89 78 20 55 41 54 41 55 41 56 41 57 48 8D A8 E8 FD FF FF 48 81 EC F0 02 00 00 0F 29 70 C8 48 8B 05 ?? ?? ?? ?? 48 33 C4 48 89 85 D0 01 00 00 48 8B D9");
    public:
        static inline __int64 handle(LocalPlayer* _this) {
            auto oFunc = hookData->getFunc<__int64, LocalPlayer*>();
            client.setLocalPlayer(_this);
            return oFunc(_this);
        }
        normalTick() : HookClass("LocalPlayer::normalTick", address)
        {
            this->Create(hookData, &handle);
        };
    };

    class swing : public HookClass {
    private:
        static inline std::unique_ptr<HookData> hookData;
        static inline uintptr_t address = MemUtils::find_signature("48 89 5C 24 10 48 89 74 24 18 48 89 7C 24 20 55 48 8D 6C 24 A9 48 81 EC A0 00 00 00 48 8B 05 ?? ?? ?? ?? 48 33 C4 48 89 45 47 0F");
    public:
        static inline bool handle(LocalPlayer* _this, SwingType swingType) {
            auto oFunc = hookData->getFunc<__int64, LocalPlayer*, SwingType>();
            
            //if (swingType == SwingType::ATTACK) {
            //    auto item = _this->getSelectedItem();
            //    if (item && item->item) {
            //        client.getGuiData()->displayClientMessage("%s", (*item->item)->fullname.c_str());
            //    }
            //}
            return oFunc(_this, swingType);
        }
        swing() : HookClass("LocalPlayer::swing", address)
        {
            this->Create(hookData, &handle);
        };
    };
}

namespace ActorHook {
}

namespace MobHook {
    class getCurrentSwingDuration : public HookClass {
    private:
        static inline std::unique_ptr<HookData> hookData;
        static inline uintptr_t address = MemUtils::find_signature("48 89 5C 24 10 48 89 6C 24 18 48 89 74 24 20 57 48 83 EC 30 8B 41");
    public:
        static inline int handle(Mob* _this) {
            auto oFunc = hookData->getFunc<int, Mob*>();
            return 30;
        }
        getCurrentSwingDuration() : HookClass("Mob::getCurrentSwingDuration", address)
        {
            this->Create(hookData, &handle);
        }
    };
}