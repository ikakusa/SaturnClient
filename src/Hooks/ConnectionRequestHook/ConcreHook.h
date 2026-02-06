#pragma once
#include "../HookManager.h"
namespace ConnectionRequestHook {
    class create : public HookClass {
    private:
        static inline std::unique_ptr<HookData> hookData;
        // シグネチャは適切なものに差し替えてください
        static inline uintptr_t address = MemUtils::find_signature("40 55 53 56 57 41 54 41 55 41 56 41 57 48 8D AC 24 28 FF FF FF 48 81 EC D8 01 00 00 48 8B 05 ?? ?? ?? ?? 48 33 C4 48 89 85 C8 00 00 00 49");

    public:
        static inline void handle(
            __int64 a1, __int64 a2, unsigned int a3, __int64 a4, __int64 a5, __int64 a6,
            std::string* selfSignedId, std::string* serverAddress, __int64 a9, __int64 a10, __int64 a11, __int64 a12,
            __int64 a13, unsigned int a14, int a15, __int64 a16, unsigned __int8 a17,
            char a18, __int64* a19, __int64* a20, __int64* a21, int a22, __int64 a23,
            std::string* platformUserId, std::string* thirdPartyName, std::string* platformOnlineId, std::string* platformOfflineId,
            unsigned __int8 a28, unsigned int* a29)
        {
            auto oFunc = hookData->getFunc<void,
                __int64, __int64, unsigned int, __int64, __int64, __int64, std::string*, std::string*,
                __int64, __int64, __int64, __int64, __int64, unsigned int, int, __int64,
                unsigned __int8, char, __int64*, __int64*, __int64*, int, __int64, std::string*,
                std::string*, std::string*, std::string*, unsigned __int8, unsigned int*>();

            logF("%s", (*selfSignedId).c_str());
            //logF("Connecting %s", (*serverAddress).c_str());

            return oFunc(a1, a2, a3, a4, a5, a6, selfSignedId, serverAddress, a9, a10, a11, a12, a13, a14,
                a15, a16, a17, a18, a19, a20, a21, a22, a23, platformUserId,
                thirdPartyName, platformOnlineId, platformOfflineId, a28, a29);
        }

        create() : HookClass("ConnectionRequest::create", address)
        {
            this->Create(hookData, &handle);
        };
    };
}