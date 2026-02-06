#pragma once
#include "easeBase.h"
#define PI 3.141592653589793

static float easeInOutExpo(float x) {
    return x == 0.f
        ? 0.f
        : x == 1.f
        ? 1.f
        : x < 0.5f ? powf(2.f, 20.f * x - 10.f) / 2.f
        : (2.f - powf(2.f, -20.f * x + 10.f)) / 2.f;
}

struct EaseInOutExpo: public Easing {
    float Update() override {
        if (!playing) return start;
        if (IsReached(progressForLoop) && repeat) {
            doLoop();
            return start;
        }
        if (t < 1.0f)
            t += ImGui::GetIO().DeltaTime * speed;

        t = ImClamp(t, 0.0f, 1.0f);

        easeValue = easeInOutExpo(t);
        return start + (end - start) * easeValue;
    }
};