#pragma once
#include "easeBase.h"
#include "easeOutBounce.h"
#define PI 3.141592653589793

static float easeInOutBounce(float x) {
    return x < 0.5f
        ? (1.f - easeOutBounce(1.f - 2.f * x)) / 2.f
        : (1.f + easeOutBounce(2.f * x - 1.f)) / 2.f;
}

struct EaseInOutBounce : public Easing {
    float Update() override {
        if (!playing) return start;
        if (IsReached(progressForLoop) && repeat) {
            doLoop();
            return start;
        }
        if (t < 1.0f)
            t += ImGui::GetIO().DeltaTime * speed;

        t = ImClamp(t, 0.0f, 1.0f);

        easeValue = easeInOutBounce(t);
        return start + (end - start) * easeValue;
    }
};