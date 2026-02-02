#pragma once
#include <Libraries.h>

class Utils;
class MemUtils;
template <typename T>
class SafeMemory {
private:
    uintptr_t offset;

public:
    constexpr SafeMemory(uintptr_t offset) : offset(offset) {}

    T& get(void* parent) const {
        uintptr_t target = reinterpret_cast<uintptr_t>(parent) + offset;

        if (!MemUtils::isReadable(target)) {
            static T _default = T();
            return _default;
        }

        return *reinterpret_cast<T*>(target);
    }

    void set(void* parent, const T& value) const {
        uintptr_t target = reinterpret_cast<uintptr_t>(parent) + offset;
        if (MemUtils::isReadable(target)) {
            *reinterpret_cast<T*>(target) = value;
        }
    }
};

#define SAFE_ACCESS(type, name, offset) \
    static constexpr SafeMemory<type> _##name{ offset }; \
    __declspec(property(get = get_##name, put = set_##name)) type name; \
    inline type get_##name() const { return _##name.get((void*)this); } \
    inline void set_##name(type val) { _##name.set((void*)this, val); }

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