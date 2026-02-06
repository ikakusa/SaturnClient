#pragma once
#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>

enum class LoopMode {
    NORMAL = 0,
    REVERSE = 1,
};

struct Easing {
    float t = 1.0f;
    float start = 0.0f;
    float end = 0.0f;
    float speed = 1.0f;
    bool repeat = false;
    LoopMode loopMode = LoopMode::NORMAL;
    bool didSecond = false;
    bool playing = false;
    bool hasPlayed = false;
    float easeValue = 0.f;
    float progressForLoop = 1.f;

    virtual void Play(float s, float e, float spd, bool once = false) {
        if (!(once && hasPlayed)) {
            start = s;
            end = e;
            speed = spd;
            t = 0.f;
            hasPlayed = true;
            playing = true;
        }
    };
    virtual void PlayTo(float e, float spd, bool resetProgress = true) {
        end = e;
        playing = true;
        speed = spd;
        if (resetProgress) t = 0.f;
    };
    virtual void setLoopProgress(float wa) {
        progressForLoop = wa;
    }
    virtual void Stop() {
        playing = false;
    }
    virtual void Resume() {
        playing = true;
    }
    virtual float Update() = 0;
    virtual bool IsFinished() const {
        return t >= 1.f;
    };
    virtual float getProgress() const {
        return t;
    }
    virtual float IsReached(float progress) {
        return t >= progress;
    }
    virtual float IsEaseReached(float progress) {
        return easeValue >= progress;
    }
    virtual void setLoop(bool state) {
        repeat = state;
    };
    virtual void setLoopMode(LoopMode mode) {
        loopMode = mode;
    }
    virtual void doLoop() {
        if (!repeat) return;
        switch (loopMode) {
        case LoopMode::NORMAL: {
            Play(start, end, speed, false);
        } break;
        case LoopMode::REVERSE: {
            Play(end, start, speed, false);
        } break;
        }
    }
};