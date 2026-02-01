#pragma once

#include <Libraries.h>
#include <MemUtils.h>

class HookData {
public:
	uintptr_t address;
	void* originalFn;
	void* callbackFn;
public:
	HookData(uintptr_t _address, void* callback) : address(_address), callbackFn(callback) {};
	~HookData() {};
	template<typename Ret, typename... Args>
	auto* getFunc() {
		using fn_t = Ret(__fastcall*)(Args...);
		return reinterpret_cast<fn_t>(originalFn);
	}
};

class HookClass {
public:
	std::string name;
	uintptr_t address;
public:
	HookClass(std::string _name, uintptr_t _addr) {
		address = _addr;
	}
	bool Disable() {

	}
	bool Create(std::unique_ptr<HookData>& data, void* callback) {
		data = std::make_unique<HookData>(address, callback);
		return MH_CreateHook((void*)address, data->callbackFn, &data->originalFn) == MH_OK;
	}
	std::string getName() const {
		return name;
	}
};

class HookManager {
private:
	std::vector<HookClass*> hookList;
public:
	bool Initialize();
	void add(HookClass* hook) {
		hookList.push_back(hook);
	};
};

extern HookManager* hooks;