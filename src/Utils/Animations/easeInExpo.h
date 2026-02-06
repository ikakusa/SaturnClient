#pragma once
#include "easeBase.h"
#define PI 3.141592653589793

static float easeInExpo(float x) {
    return x == 0.f ? 0.f : powf(2.f, 10.f * x - 10.f);
}

struct EaseInExpo : public Easing {
    float Update() override {
        if (!playing) return start;
        if (IsReached(progressForLoop) && repeat) {
            doLoop();
            return start;
        }
        if (t < 1.0f)
            t += ImGui::GetIO().DeltaTime * speed;

        t = ImClamp(t, 0.0f, 1.0f);

        easeValue = easeInExpo(t);
        return start + (end - start) * easeValue;
    }
};