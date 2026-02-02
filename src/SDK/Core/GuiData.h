#pragma once
class GuiData {
public:
	SAFE_ACCESS(float, windowSizeReal, 0x40);
	SAFE_ACCESS(float, windowSize, 0x48);
	SAFE_ACCESS(int, guiScale, 0x5C);
};