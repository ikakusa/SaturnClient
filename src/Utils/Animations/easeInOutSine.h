#pragma once
#include "easeBase.h"
#define PI 3.141592653589793

static float easeInOutSine(float x) {
    return -(cosf(PI * x) - 1.f) / 2.f;
}

struct EaseInOutSine : public Easing {
    float Update() override {
        if (!playing) return start;
        if (IsReached(progressForLoop) && repeat) {
            doLoop();
            return start;
        }
        if (t < 1.0f)
            t += ImGui::GetIO().DeltaTime * speed;

        t = ImClamp(t, 0.0f, 1.0f);

        easeValue = easeInOutSine(t);
        return start + (end - start) * easeValue;
    }
};