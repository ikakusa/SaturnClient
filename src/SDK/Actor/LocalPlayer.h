#pragma once
#include "Player.h"

class LocalPlayer : public Player {
public:
	void displayClientMessage(const char* str, ...);
};