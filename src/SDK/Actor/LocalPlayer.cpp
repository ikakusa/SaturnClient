#include "LocalPlayer.h"
#include <Utils.h>

void LocalPlayer::displayClientMessage(const char* str, ...) {
	va_list arg;
	va_start(arg, str);
	std::string msg = Utils::formatString(str, arg);
	static uintptr_t address = MemUtils::find_signature("48 89 5C 24 20 55 56 57 48 83 EC 60 48 8B 05 ?? ?? ?? ?? 48 33 C4 48 89 44 24 50 49 8B F8");
	using fun_t = void(__fastcall*)(LocalPlayer*, const std::string&, const std::optional<std::string>);
	auto func = reinterpret_cast<fun_t>(address);
	std::optional<std::string> filtered = str;
	func(this, msg, filtered);
	va_end(arg);
}