#pragma once

#include "../HookManager.h"

namespace ScreenContextHook {
    class drawSplashText : public HookClass {
    private:
        static inline std::unique_ptr<HookData> hookData;
        static inline uintptr_t address = MemUtils::find_signature("48 8B C4 48 89 58 20 55 56 57 41 56 41 57 48 81 EC 20");
    public:
        static inline __int64 handle(ScreenContext* _this, __int64 font, const std::string& text, float* position, float* color, float angle, float s) {
            auto oFunc = hookData->getFunc<__int64, ScreenContext*, __int64, const std::string&, float*, float*, float, float>();
            std::string aaa(Utils::u8ToString(u8"私バカです\n私バカです\n私バカです"));
            color[0] = 0.27058823529;
            color[1] = 0.14901960784;
            color[2] = 0.85490196078;
            angle = 90.f;
            return oFunc(_this, font, aaa, position, color, angle, 1.5f);
        }
        drawSplashText() : HookClass("ScreenContext::drawSplashText", address)
        {
            this->Create(hookData, &handle);
        };
    };
}