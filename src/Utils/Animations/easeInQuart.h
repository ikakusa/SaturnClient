#pragma once
#include "easeBase.h"
#define PI 3.141592653589793

static float easeInQuart(float x) {
    return x * x * x * x;
}

struct EaseInQuart : public Easing {
    float Update() override {
        if (!playing) return start;
        if (IsReached(progressForLoop) && repeat) {
            doLoop();
            return start;
        }
        if (t < 1.0f)
            t += ImGui::GetIO().DeltaTime * speed;

        t = ImClamp(t, 0.0f, 1.0f);

        easeValue = easeInQuart(t);
        return start + (end - start) * easeValue;
    }
};