#pragma once
#include <Libraries.h>
#include <SDK.h>
#include <MemUtils.h>

class LocalPlayer;
class ClientInstance;
class GuiData;

template <typename T>
class SafeMember {
private:
	using BaseType = std::remove_pointer_t<T>;
	std::shared_ptr<BaseType> value;
public:
	SafeMember& set(const T& newMem) {
		value = std::shared_ptr<BaseType>(newMem, [](BaseType* p) { });
		return *this;
	}
	T get() {
		auto res = value.get();
		if (!res || !MemUtils::isReadable(reinterpret_cast<uintptr_t>(res))) return nullptr;
		return res;
	}
	SafeMember() : value(std::shared_ptr<BaseType>(nullptr, [](BaseType* p) { delete p; })) {}
	SafeMember(T defaultValue) : value(std::shared_ptr<BaseType>(defaultValue, [](BaseType* p) { })) {}
public:
	operator T& () {
		return get();
	}
	operator const T& () {
		return get();
	}
	T operator->() { return value.get(); }
	T& operator*() {
		return *value;
	}
	SafeMember& operator=(T newmem) {
		value = std::shared_ptr<BaseType>(newmem, [](BaseType* p) {});
		return *this;
	}

	SafeMember& operator=(const SafeMember& other) {
		if (this != &other) {
			value = other.value;
		}
		return *this;
	}
};

class ClientData {
private:
	static inline std::string ClientName = "McDonalds";
	static inline bool running = false;
	static inline HMODULE dllMod = NULL;
private:
	static inline SafeMember<LocalPlayer*> localPlayer;
	static inline SafeMember<ClientInstance*> clientInstance;
	static inline SafeMember<GuiData*> guiData;
public:
	void setLocalPlayer(LocalPlayer* lp) {
		localPlayer = lp;
	}
	void setClientInstance(ClientInstance* ci) {
		clientInstance = ci;
	}
	LocalPlayer* getLocalPlayer() {
		return localPlayer.get();
	}
	ClientInstance* getClientInstance() {
		return clientInstance.get();
	}
	GuiData* getGuiData() {
		return guiData.get();
	}
public:

public:
	static HMODULE getMod() {
		return dllMod;
	}
	static void setMod(HMODULE modd) {
		dllMod = modd;
	}
	static bool isRunning() {
		return running;
	}
	static void setRunning(bool state) {
		running = state;
	}
	static std::string getName() {
		return ClientName;
	}
};

extern ClientData client;