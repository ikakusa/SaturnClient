#pragma once
#include "easeBase.h"
static float easeOutBounce(float x) {
    float n1 = 7.5625f;
    float d1 = 2.75f;

    if (x < 1.f / d1) {
        return n1 * x * x;
    }
    else if (x < 2.f / d1) {
        return n1 * (x -= 1.5f / d1) * x + 0.75f;
    }
    else if (x < 2.5f / d1) {
        return n1 * (x -= 2.25f / d1) * x + 0.9375f;
    }
    else {
        return n1 * (x -= 2.625f / d1) * x + 0.984375f;
    }
}

struct EaseOutBounce : public Easing {
    float Update() override {
        if (!playing) return start;
        if (IsReached(progressForLoop) && repeat) {
            doLoop();
            return start;
        }
        if (t < 1.0f)
            t += ImGui::GetIO().DeltaTime * speed;

        t = ImClamp(t, 0.0f, 1.0f);

        easeValue = easeOutBounce(t);
        return start + (end - start) * easeValue;
    }
};