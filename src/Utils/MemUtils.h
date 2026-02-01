#pragma once
#include <Libraries.h>
class MemUtils {
public:
	static inline uintptr_t getBase() {
		static uintptr_t mcaddr = reinterpret_cast<uintptr_t>(GetModuleHandleA("Minecraft.Windows.exe"));
		return mcaddr;
	}
	static inline unsigned long GetMinecraftSize() {
		HMODULE base = GetModuleHandleA("Minecraft.Windows.exe");
		if (base == nullptr) return 0;

		MODULEINFO moduleInfo;
		if (!GetModuleInformation(GetCurrentProcess(), base, &moduleInfo, sizeof(MODULEINFO)))
			return 0;

		return moduleInfo.SizeOfImage;
	}
	static inline uintptr_t find_signature(std::string pattern) {
		auto sig = hat::parse_signature(pattern);
		auto base = reinterpret_cast<std::byte*>(getBase());
		auto end = base + GetMinecraftSize();
		if (auto res = hat::find_pattern(base, end, sig.value()); res.has_result()) {
			return reinterpret_cast<uintptr_t>(res.get());
		}
		return 0u;
	}
	template <typename Return, int Index, typename... Args>
	static inline Return CallVFunc(void* _class, Args... arglist) {
		using func_type = Return(*)(void*, decltype(arglist)...);
		return reinterpret_cast<func_type>((*(uintptr_t**)_class)[Index])(_class, arglist...);
	}
};