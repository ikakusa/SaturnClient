#pragma once
#include "easeBase.h"
#define PI 3.141592653589793

static float easeInSine(float x) {
    return 1.f - cosf((x * PI) / 2.f);
}

struct EaseInSine : public Easing {
    float Update() override {
        if (!playing) return start;
        if (IsReached(progressForLoop) && repeat) {
            doLoop();
            return start;
        }
        if (t < 1.0f)
            t += ImGui::GetIO().DeltaTime * speed;

        t = ImClamp(t, 0.0f, 1.0f);

        easeValue = easeInSine(t);
        return start + (end - start) * easeValue;
    }
};