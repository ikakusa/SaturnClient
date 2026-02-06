#pragma once
class Item;
class CompoundTag;
class ItemStackBase {
public:
	uintptr_t** vTable;
	Item** item;
	SAFE_ACCESS(CompoundTag*, tag, 0x10);
};