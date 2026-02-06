#pragma once
#include "easeBase.h"
#define PI 3.141592653589793

static float easeInOutQuart(float x) {
    return x < 0.5f ? 8.f * x * x * x * x : 1.f - powf(-2.f * x + 2.f, 4.f) / 2.f;
}

struct EaseInOutQuart : public Easing {
    float Update() override {
        if (!playing) return start;
        if (IsReached(progressForLoop) && repeat) {
            doLoop();
            return start;
        }
        if (t < 1.0f)
            t += ImGui::GetIO().DeltaTime * speed;

        t = ImClamp(t, 0.0f, 1.0f);

        easeValue = easeInOutQuart(t);
        return start + (end - start) * easeValue;
    }
};