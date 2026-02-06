#pragma once
#include <MemUtils.h>

class ItemStack;
class Inventory {
public:
	ItemStack* getItem(int slot) { //1.21.132
		return MemUtils::CallVFunc<ItemStack*, 7, int>(this, slot);
	}
};