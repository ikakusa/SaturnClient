#include "HookManager.h"

#include "SystemHook/SystemHook.h"
#include "DirectXHook/DirectXHook.h"
#include "ActorHook/ActorHook.h"
#include "ClientInstanceHook/ClientInstanceHook.h"
#include "ScreenContextHook/ScreenContextHook.h"
#include "OptionsHook/OptionsHook.h"
#include "ConnectionRequestHook/ConcreHook.h"
#include "LoopBackPacketSender/LoopbackPacketSender.h"
bool HookManager::Initialize() {
	logF("Initializing hooks");
	DirectXHook::Initialize();
	MH_Initialize();
	{
		add(new SystemHook::FreeLibraryFn());
		add(new ClientInstanceHook::update());
		add(new LocalPlayerHook::normalTick());
		add(new LocalPlayerHook::swing());
		add(new MobHook::getCurrentSwingDuration());
		add(new ScreenContextHook::drawSplashText());
		add(new OptionsHook::getBrightness());
		add(new ConnectionRequestHook::create());
		add(new LoopbackPacketSenderHook::sendToServer());
	}
	MH_EnableHook(MH_ALL_HOOKS);
	logF("Initialized hooks");
	return true;
}

bool HookManager::Restore() {
	logF("Deleting hooks");
	DirectXHook::shutdown();
	for (size_t i = 0; i < hookList.size(); ) {
		if (hookList[i]->Disable()) {
			delete hookList[i];
			hookList.erase(hookList.begin() + i);
		}
		else {
			++i;
		}
	}
	hookList.clear();
	delete hooks;
	MH_Uninitialize();
	logF("Deleted hooks");
	return true;
}

HookManager* hooks = new HookManager();