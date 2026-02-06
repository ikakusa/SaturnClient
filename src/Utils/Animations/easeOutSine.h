#pragma once
#include "easeBase.h"
#define PI 3.141592653589793

static float easeOutSine(float x) {
    return sinf((x * PI) / 2.f);
}

struct EaseOutSine : public Easing {
    float Update() override {
        if (!playing) return start;
        if (IsReached(progressForLoop) && repeat) {
            doLoop();
            return start;
        }
        if (t < 1.0f)
            t += ImGui::GetIO().DeltaTime * speed;

        t = ImClamp(t, 0.0f, 1.0f);

        easeValue = easeOutSine(t);
        return start + (end - start) * easeValue;
    }
};