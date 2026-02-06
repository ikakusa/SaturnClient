#pragma once
class Inventory;
class PlayerInventory {
public:
	SAFE_ACCESS(int, selectedSlot, 0x10); //1.21.132
	SAFE_ACCESS(char, selectedContainerID, 0xB0); //1.21.132
	SAFE_ACCESS(Inventory*, inventory, 0xB8); //1.21.132
};