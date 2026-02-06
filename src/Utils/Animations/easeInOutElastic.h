#pragma once
#include "easeBase.h"
#define PI 3.141592653589793

static float easeInOutElastic(float x) {
    float c4 = (2.f * PI) / 3.f;

    return x == 0.f
        ? 0.f
        : x == 1.f
        ? 1.f
        : powf(2.f, -10.f * x) * sinf((x * 10.f - 0.75f) * c4) + 1.f;
}

struct EaseInOutElastic : public Easing {
    float Update() override {
        if (!playing) return start;
        if (IsReached(progressForLoop) && repeat) {
            doLoop();
            return start;
        }
        if (t < 1.0f)
            t += ImGui::GetIO().DeltaTime * speed;

        t = ImClamp(t, 0.0f, 1.0f);

        easeValue = easeInOutElastic(t);
        return start + (end - start) * easeValue;
    }
};