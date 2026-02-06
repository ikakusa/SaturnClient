#pragma once
class Item {
public:
	SAFE_ACCESS(std::string, tileName, 0xB0);
	SAFE_ACCESS(std::string, name, 0xD8);
	SAFE_ACCESS(std::string, _namespace, 0x100);
	SAFE_ACCESS(std::string, fullname, 0x128);
};