#pragma once
#include "easeBase.h"
static float easeInOutBack(float x) {
    float c1 = 1.70158f;
    float c2 = c1 * 1.525f;

    return x < 0.5f
        ? (pow(2.f * x, 2.f) * ((c2 + 1.f) * 2.f * x - c2)) / 2.f
        : (pow(2.f * x - 2.f, 2.f) * ((c2 + 1.f) * (x * 2.f - 2.f) + c2) + 2.f) / 2.f;
}

struct EaseInOutBack : public Easing {
    float Update() override {
        if (!playing) return start;
        if (IsReached(progressForLoop) && repeat) {
            doLoop();
            return start;
        }
        if (t < 1.0f)
            t += ImGui::GetIO().DeltaTime * speed;

        t = ImClamp(t, 0.0f, 1.0f);

        easeValue = easeInOutBack(t);
        return start + (end - start) * easeValue;
    }
};