#pragma once
class GuiData;
class ClientInstance {
public:
	SafeMemory<GuiData*, ClientInstance> guiData{ this, 0x648 }; //1.21.132
};