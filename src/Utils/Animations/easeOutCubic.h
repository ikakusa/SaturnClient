#pragma once
#include "easeBase.h"
#define PI 3.141592653589793

static float easeOutCubic(float x) {
    return 1 - powf(1.f - x, 3.f);
}

struct EaseOutCubic : public Easing {
    float Update() override {
        if (!playing) return start;
        if (IsReached(progressForLoop) && repeat) {
            doLoop();
            return start;
        }
        if (t < 1.0f)
            t += ImGui::GetIO().DeltaTime * speed;

        t = ImClamp(t, 0.0f, 1.0f);

        easeValue = easeOutCubic(t);
        return start + (end - start) * easeValue;
    }
};