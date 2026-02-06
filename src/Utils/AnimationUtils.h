#pragma once
#include <Animations/easeInCubic.h>
#include <Animations/easeInOutBack.h>
#include <Animations/easeInOutSine.h>
#include <Animations/easeInSine.h>
#include <Animations/easeOutBounce.h>
#include <Animations/easeOutCubic.h>
#include <Animations/easeOutSine.h>

template <typename AnimT>
struct Animation : public AnimT {
};