#pragma once
#include "easeBase.h"
#define PI 3.141592653589793

static float easeOutExpo(float x) {
    return x == 1.f ? 1.f : 1.f - powf(2.f, -10.f * x);
}

struct EaseOutExpo : public Easing {
    float Update() override {
        if (!playing) return start;
        if (IsReached(progressForLoop) && repeat) {
            doLoop();
            return start;
        }
        if (t < 1.0f)
            t += ImGui::GetIO().DeltaTime * speed;

        t = ImClamp(t, 0.0f, 1.0f);

        easeValue = easeOutExpo(t);
        return start + (end - start) * easeValue;
    }
};