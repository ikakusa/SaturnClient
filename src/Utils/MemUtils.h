#pragma once
#include <Libraries.h>

template <typename TYPE, typename OWNER>
class SafeMemory {
private:
	int offset;
	OWNER* base;
public:
	SafeMemory(OWNER* _base, int _offset) : offset(_offset), base(_base) {};
	TYPE& get() {
		if (!base) return nullptr;
		return *reinterpret_cast<TYPE*>(reinterpret_cast<uintptr_t>(base) + offset);
	}
	void set(TYPE value) {
		*reinterpret_cast<TYPE*>(reinterpret_cast<uintptr_t>(base) + offset) = value;
	}
	~SafeMemory() = default;
public:
	operator TYPE&() {
		return get();
	}
	operator const TYPE& () {
		return get();
	}
};

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
	static inline bool isReadable(uintptr_t ptr_addr) {
		void* ptr = reinterpret_cast<void*>(ptr_addr);
		if (!ptr) return false;

		MEMORY_BASIC_INFORMATION mbi;
		// メモリの情報を取得
		if (VirtualQuery(ptr, &mbi, sizeof(mbi)) == 0) return false;

		// 状態が「COMMIT（割り当て済み）」かつ
		// 保護属性が「NOACCESS」や「GUARD」ではないことを確認
		if (mbi.State != MEM_COMMIT) return false;
		if (mbi.Protect & (PAGE_NOACCESS | PAGE_GUARD)) return false;

		// 読み取り許可（READONLY, READWRITE, EXECUTE_READ 等）があるか
		return (mbi.Protect & (PAGE_READONLY | PAGE_READWRITE | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE));
	}
	static inline bool isVTableReadable(uintptr_t addr) {
		uintptr_t vtable = *reinterpret_cast<uintptr_t*>(addr);
		if (!MemUtils::isReadable(vtable)) return false;
		return true;
	}
};