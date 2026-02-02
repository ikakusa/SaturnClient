#pragma once
#include <MathUtils.h>
struct StateVectorComponent { //1.21.132
public:
	vec3<float> position;
	vec3<float> posDelta;
	vec3<float> velocity;
};