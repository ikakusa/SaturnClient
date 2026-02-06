#pragma once
#include "easeBase.h"
#define PI 3.141592653589793

static float easeInOutQuad(float x) {
    return x < 0.5f ? 2.f * x * x : 1.f - powf(-2.f * x + 2.f, 2.f) / 2.f;
}

struct EaseInOutQuad : public Easing {
    float Update() override {
        if (!playing) return start;
        if (IsReached(progressForLoop) && repeat) {
            doLoop();
            return start;
        }
        if (t < 1.0f)
            t += ImGui::GetIO().DeltaTime * speed;

        t = ImClamp(t, 0.0f, 1.0f);

        easeValue = easeInOutQuad(t);
        return start + (end - start) * easeValue;
    }
};