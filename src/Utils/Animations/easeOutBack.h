#pragma once
#include "easeBase.h"
#define PI 3.141592653589793

static float easeOutBack(float x) {
    float c1 = 1.70158f;
    float c3 = c1 + 1.f;

    return 1.f + c3 * powf(x - 1.f, 3.f) + c1 * powf(x - 1.f, 2.f);
}

struct EaseOutBack : public Easing {
    float Update() override {
        if (!playing) return start;
        if (IsReached(progressForLoop) && repeat) {
            doLoop();
            return start;
        }
        if (t < 1.0f)
            t += ImGui::GetIO().DeltaTime * speed;

        t = ImClamp(t, 0.0f, 1.0f);

        easeValue = easeOutBack(t);
        return start + (end - start) * easeValue;
    }
};