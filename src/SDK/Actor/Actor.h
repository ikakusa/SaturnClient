#pragma once
#include <MemUtils.h>
class Level;
struct StateVectorComponent;
struct RotationComponent;
class Actor {
public:
	SAFE_ACCESS(StateVectorComponent*, stateVector, 0x218); //1.21.132
	SAFE_ACCESS(RotationComponent*, rotation, 0x228); //1.21.132
	SAFE_ACCESS(Level*, level, 0x1D8); //1.21.132
};