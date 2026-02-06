#pragma once
#include "../HookManager.h"
#include <DX11/DirectX11.h>
#include <AnimationUtils.h>

namespace ScreenContextHook {
    class drawSplashText : public HookClass {
    private:
        static inline std::unique_ptr<HookData> hookData;
        static inline uintptr_t address = MemUtils::find_signature("48 8B C4 48 89 58 20 55 56 57 41 56 41 57 48 81 EC 20");
    public:
        static inline __int64 handle(ScreenContext* _this, __int64 font, const std::string& text, float* position, float* color, float angle, float s) {
            static auto start = std::chrono::steady_clock::now();
            auto oFunc = hookData->getFunc<__int64, ScreenContext*, __int64, const std::string&, float*, float*, float, float>();
            if ((uintptr_t)_ReturnAddress() == MemUtils::getBase() + 0xDE0DF0) return 0;
            if (!ImGui::GetCurrentContext()) return oFunc(_this, font, text, position, color, angle, s);
            static Animation<EaseOutBounce> ease;
            static Animation<EaseInOutBack> easeAngle;
            easeAngle.setLoop(true);
            easeAngle.setLoopMode(LoopMode::REVERSE);
            easeAngle.setLoopProgress(0.9745998633f);
            easeAngle.Play(0.f, 360.f, 0.2f, true);

            ease.setLoop(true);
            ease.setLoopMode(LoopMode::REVERSE);
            ease.Play(0.f, 35.f, 0.2f, true);
            float ss = ease.Update();
            float newangle = easeAngle.Update();
            
            // baka script
            auto BAKA = Utils::u8ToString(u8"私バカです。");
            auto length = BAKA.size();
            static bool time_to_baka = true;
            static int count = 0 ;
            auto awaaa = BAKA.substr(0, count);
            auto now = std::chrono::steady_clock::now();
            static auto manuke = std::chrono::steady_clock::time_point();
            static auto tick_vertical_bar = std::chrono::steady_clock::time_point();
            static bool typed = false;
            auto woah = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count() ;
            if (!typed && count < length && woah >= 250) {
                start = std::chrono::steady_clock::now() ;
                manuke = std::chrono::steady_clock::now() ;
                count++;
            }
            if (count == length) {
                typed = true;
            }
            if (count > 0 && typed && woah >= 15 && std::chrono::duration_cast<std::chrono::milliseconds>(now - manuke).count() >= 800) {
                start = std::chrono::steady_clock::now();
                count--;
            }
            if (typed && count == 0) {
                typed = false;
            }
            //
            color[0] = 0.27058823529;
            color[1] = 0.14901960784;
            color[2] = 0.85490196078;
            auto whyasmr = easeAngle.Update();
            auto whyasmr2 = ease.Update();
            return oFunc(_this, font, awaaa + std::string(!awaaa.empty() ? "ﾂｧe|" : ""), position, color, angle, s * 2.f);
        }
        drawSplashText() : HookClass("ScreenContext::drawSplashText", address)
        {
            this->Create(hookData, &handle);
        };
    };
}