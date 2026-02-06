#pragma once
#include "../HookManager.h"

namespace OptionsHook {
    class getBrightness : public HookClass {
    private:
        static inline std::unique_ptr<HookData> hookData;
        static inline uintptr_t address = MemUtils::find_signature("48 83 EC 28 48 8B 01 48 8D 54 24 30 41 B8 36 00");
    public:
        static inline float handle(__int64* _this) {
            auto oFunc = hookData->getFunc<float, __int64*>();
            return 20.f;
            //return oFunc(_this);
        }
        getBrightness() : HookClass("LocalPlayer::normalTick", address)
        {
            this->Create(hookData, &handle);
        };
    };
}