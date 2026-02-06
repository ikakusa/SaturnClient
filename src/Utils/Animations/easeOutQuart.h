#pragma once
#include "easeBase.h"
#define PI 3.141592653589793

static float easeOutQuart(float x) {
    return 1.f - powf(1.f - x, 4.f);
}

struct EaseOutQuart : public Easing {
    float Update() override {
        if (!playing) return start;
        if (IsReached(progressForLoop) && repeat) {
            doLoop();
            return start;
        }
        if (t < 1.0f)
            t += ImGui::GetIO().DeltaTime * speed;

        t = ImClamp(t, 0.0f, 1.0f);

        easeValue = easeOutQuart(t);
        return start + (end - start) * easeValue;
    }
};