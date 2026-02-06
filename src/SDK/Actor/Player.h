#pragma once
#include "../Inventory/Inventory.h"
#include "../Inventory/PlayerInventory.h"
#include "Actor.h"	
class GameMode;
class ItemStack;
class PlayerInventory;
class Player : public Actor {
public:
	SAFE_ACCESS(PlayerInventory*, supplies, 0x5B8); //1.21.132
	SAFE_ACCESS(GameMode*, gameMode, 0xA78); //1.21.132
public:
	ItemStack* getSelectedItem() { //1.21.132
		auto supplies = this->supplies;
		int selected = supplies->selectedSlot;
		//if (supplies->selectedContainerID) {
		//	return nullptr;
		//}
		return supplies->inventory->getItem(selected);
	}
};