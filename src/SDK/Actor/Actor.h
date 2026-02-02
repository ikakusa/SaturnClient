#pragma once
#include <MemUtils.h>
class Level;
class Actor {
public:
	SafeMemory<Level*, Actor> level{ this, 0x1D8 }; //1.21.132
};