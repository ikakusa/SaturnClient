#pragma once
#include <Utils.h>
class GuiData {
public:
	SAFE_ACCESS(vec2<float>, windowSizeReal, 0x40); //1.21.132
	SAFE_ACCESS(vec2<float>, windowSize, 0x48); //1.21.132
	SAFE_ACCESS(int, guiScale, 0x5C); //1.21.132
public:
	void displayClientMessage(const char* str, ...) {
		va_list arg;
		va_start(arg, str);
		std::string msg = Utils::formatString(str, arg);
		static uintptr_t address = MemUtils::find_signature("40 55 53 56 57 41 56 48 8D AC 24 A0 FE");
		using funfun = void(__fastcall*)(GuiData*, const std::string&, const std::optional<std::string>&);
		funfun funfunfun = reinterpret_cast<funfun>(address);
		funfunfun(this, msg, std::make_optional<std::string>(msg));
	}
};