#pragma once
class GuiData {
public:
	SafeMemory<float*, GuiData> windowSizeReal{ this, 0x40 }; //1.21.132
	SafeMemory<float*, GuiData> windowSize{ this, 0x48 }; //1.21.132
	SafeMemory<float, GuiData> guiScale{ this, 0x5C }; //1.21.132
};