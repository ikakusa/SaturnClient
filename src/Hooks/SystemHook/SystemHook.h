#pragma once
#include "../HookManager.h"

namespace SystemHook {
    class FreeLibraryFn : public HookClass {
    private:
        static inline std::unique_ptr<HookData> hookData;
        static inline uintptr_t address = (uintptr_t)FreeLibraryAndExitThread;
    public:
        static inline void handle(HMODULE handle, DWORD exitCode) {
            auto oFunc = hookData->getFunc<void, HMODULE, DWORD>();
            if (handle == client.getMod()) {
                client.setRunning(false);
                return;
            }
            return oFunc(handle, exitCode);
        }
        FreeLibraryFn() : HookClass("FreeLibraryAndExitThread", address)
        {
            this->Create(hookData, &handle);
        };
    };
}