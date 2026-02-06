#pragma once
#include "easeBase.h"
#define PI 3.141592653589793

static float easeInBack(float x) {
    float c1 = 1.70158f;
    float c3 = c1 + 1.f;

    return c3 * x * x * x - c1 * x * x;
}

struct EaseInBack : public Easing {
    float Update() override {
        if (!playing) return start;
        if (IsReached(progressForLoop) && repeat) {
            doLoop();
            return start;
        }
        if (t < 1.0f)
            t += ImGui::GetIO().DeltaTime * speed;

        t = ImClamp(t, 0.0f, 1.0f);

        easeValue = easeInBack(t);
        return start + (end - start) * easeValue;
    }
};