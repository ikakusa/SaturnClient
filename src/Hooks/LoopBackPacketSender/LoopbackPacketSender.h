#pragma once
#include "../HookManager.h"

namespace LoopbackPacketSenderHook {
    class sendToServer : public HookClass {
    private:
        static inline std::unique_ptr<HookData> hookData;
        static inline uintptr_t address = MemUtils::find_signature("48 89 5C 24 18 57 48 81 EC 60 02 00 00 48 8B 05 ?? ?? ?? ?? 48 33 C4 48 89 84 24 50 02 00 00 0F");
    public:
        static inline __int64 handle(LoopbackPacketSender* _this, Packet* packet) {
            auto oFunc = hookData->getFunc<__int64, LoopbackPacketSender*, Packet*>();
            return oFunc(_this, packet);
        }
        sendToServer() : HookClass("LoopbackPacketSender::sendToServer", address)
        {
            this->Create(hookData, &handle);
        };
    };
}