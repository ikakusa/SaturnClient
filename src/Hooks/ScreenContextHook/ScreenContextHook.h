#pragma once
#include "../HookManager.h"
#include <DX11/DirectX11.h>
#include <AnimationUtils.h>

#define バカ！ bool
#define バカス int
#define バカ ++
#define ばか true
#define 馬鹿 false
#define ばかあ static
#define アホ auto
#define あほ float
#define あほお std::chrono::steady_clock
#define カス ::now()
#define かす std::chrono
#define カス！ --
#define 間抜け ;

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
            アホ BAKA = Utils::u8ToString(u8"私魚です。") 間抜け
            アホ length = BAKA.size() 間抜け
            ばかあ バカス ボケ = 0 間抜け
            アホ awaaa = BAKA.substr(0, ボケ) 間抜け
            アホ baka = あほお カス 間抜け
            ばかあ アホ manuke = あほお::time_point() 間抜け
            ばかあ バカ！ aho = 馬鹿 間抜け
            アホ woah = かす::duration_cast<かす::milliseconds>(baka - start).count() 間抜け
            if (ボケ < length && woah >= 250) {
                start = あほお カス 間抜け
                manuke = あほお カス 間抜け
                aho = ばか 間抜け
                ボケ バカ 間抜け
            }
            if (ボケ > 0 && aho && woah >= 75 && (manuke - baka).count() >= 800) {
                ボケ カス！ 間抜け
            }
            else if (aho && ボケ == 0) {
                aho = 馬鹿 間抜け
            }
            //
            color[0] = 0.27058823529;
            color[1] = 0.14901960784;
            color[2] = 0.85490196078;
            auto whyasmr = easeAngle.Update();
            auto whyasmr2 = ease.Update();
            return oFunc(_this, font, awaaa, position, color, angle, s * 2.f);
        }
        drawSplashText() : HookClass("ScreenContext::drawSplashText", address)
        {
            this->Create(hookData, &handle);
        };
    };
}