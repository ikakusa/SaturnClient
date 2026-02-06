#pragma once
#include <Animations/easeInBack.h>
#include <Animations/easeInBounce.h>
#include <Animations/easeInCirc.h>
#include <Animations/easeInCubic.h>
#include <Animations/easeInElastic.h>
#include <Animations/easeInExpo.h>
#include <Animations/easeInQuint.h>
#include <Animations/easeInQuad.h>
#include <Animations/easeInQuart.h>
#include <Animations/easeInQuint.h>
#include <Animations/easeInSine.h>

#include <Animations/easeInOutBack.h>
#include <Animations/easeInOutBounce.h>
#include <Animations/easeInOutCubic.h>
#include <Animations/easeInOutCirc.h>
#include <Animations/easeInOutElastic.h>
#include <Animations/easeInOutExpo.h>
#include <Animations/easeInOutQuad.h>
#include <Animations/easeInOutQuart.h>
#include <Animations/easeInOutQuint.h>
#include <Animations/easeInOutSine.h>

#include <Animations/easeOutBack.h>
#include <Animations/easeOutBounce.h>
#include <Animations/easeOutCirc.h>
#include <Animations/easeOutCubic.h>
#include <Animations/easeOutElastic.h>
#include <Animations/easeOutExpo.h>
#include <Animations/easeOutQuad.h>
#include <Animations/easeOutQuart.h>
#include <Animations/easeOutQuint.h>
#include <Animations/easeOutSine.h>

template <typename AnimT>
struct Animation : public AnimT {
};