#pragma once
class GuiData;
class MinecraftGame;
class LoopbackPacketSender;
class ClientInstance {
public:
	SAFE_ACCESS(MinecraftGame*, minecraftGame, 0x1A0); //1.21.132
	SAFE_ACCESS(GuiData*, guiData, 0x648); //1.21.132
	SAFE_ACCESS(LoopbackPacketSender*, packetSender, 0x1C8); //1.21.132
public:
	void grabMouse() {  // index: 311
		using func_t = void(__fastcall*)(ClientInstance*);
		func_t func = reinterpret_cast<func_t>(MemUtils::find_signature("40 53 48 83 EC 20 48 8B 01 48 8B D9 48 8B 80 20 05 00 00 FF 15 ?? ?? ?? ?? 84 C0 74 1D 48 8B 8B A0 01 00 00 48 8B 01 48 8B 80 90"));
	}
	void releaseMouse() { // index: 312
		using func_t = void(__fastcall*)(ClientInstance*);
		func_t func = reinterpret_cast<func_t>(MemUtils::find_signature("40 53 48 83 EC 20 48 8B 01 48 8B D9 48 8B 80 20 05 00 00 FF 15 ?? ?? ?? ?? 84 C0 74 1D 48 8B 8B A0 01 00 00 48 8B 01 48 8B 80 98"));
	}
};