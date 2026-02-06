#pragma once
#include "easeBase.h"
#include "easeOutBounce.h"
#define PI 3.141592653589793

static float easeInBounce(float x) {
    return 1.f - easeOutBounce(1.f - x);
}

struct EaseInBounce : public Easing {
    float Update() override {
        if (!playing) return start;
        if (IsReached(progressForLoop) && repeat) {
            doLoop();
            return start;
        }
        if (t < 1.0f)
            t += ImGui::GetIO().DeltaTime * speed;

        t = ImClamp(t, 0.0f, 1.0f);

        easeValue = easeInBounce(t);
        return start + (end - start) * easeValue;
    }
};