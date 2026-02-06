#pragma once
#include <MemUtils.h>
class Level;
struct StateVectorComponent;
struct RotationComponent;
enum class SwingType : char {
    PLACE = 1,
    BREAK = 2,
    ATTACK = 4,
    DROP = 7,
};
class Actor {
public:
	SAFE_ACCESS(StateVectorComponent*, stateVector, 0x218); //1.21.132
	SAFE_ACCESS(RotationComponent*, rotation, 0x228); //1.21.132
	SAFE_ACCESS(Level*, level, 0x1D8); //1.21.132
public:
    template<typename RetType>
    RetType getComponent(uintptr_t address) {
        auto func = reinterpret_cast<RetType(*)(__int64*, int*)>((void*)address);
        __int64* a1 = *(__int64**)((__int64)this + 0x10);
        int a2 = *(DWORD*)((__int64)this + 0x18);
        return func(a1, &a2);
    }
};