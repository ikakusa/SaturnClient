#pragma once
#include "../HookManager.h"

namespace ClientInstanceHook {
    class update : public HookClass {
    private:
        static inline std::unique_ptr<HookData> hookData;
        static inline uintptr_t address = MemUtils::find_signature("48 89 5C 24 10 48 89 74 24 18 48 89 7C 24 20 55 41 54 41 55 41 56 41 57 48 8D AC 24 F0 FB FF FF 48 81 EC 10 05 00 00 48 8B 05 ?? ?? ?? ?? 48 33 C4 48 89 85 00 04 00 00 44");
    public:
        static inline __int64 handle(ClientInstance* _this, int wa) {
            auto oFunc = hookData->getFunc<__int64, ClientInstance*, int>();
            client.setClientInstance(_this);
            client.setGuiData(_this->guiData);
            return oFunc(_this, wa);
        }
        update() : HookClass("LocalPlayer::normalTick", address)
        {
            this->Create(hookData, &handle);
        };
    };
}