#pragma once

#include "../HookManager.h"

namespace LocalPlayerHook {
    class normalTick : public HookClass {
    private:
        static inline std::unique_ptr<HookData> hookData;
        static inline uintptr_t address = MemUtils::find_signature("48 8B C4 48 89 58 10 48 89 70 18 48 89 78 20 55 41 54 41 55 41 56 41 57 48 8D A8 E8 FD FF FF 48 81 EC F0 02 00 00 0F 29 70 C8 48 8B 05 ?? ?? ?? ?? 48 33 C4 48 89 85 D0 01 00 00 48 8B D9");
    public:
        static inline __int64 handle(__int64 _this) {
            auto oFunc = hookData->getFunc<__int64, __int64>();
            return oFunc(_this);
        }
        normalTick() : HookClass("LocalPlayer::normalTick", address)
        {
            this->Create(hookData, &handle);
        };
    };
}