#include "HookManager.h"

#include "SystemHook/SystemHook.h"
#include "ActorHook/ActorHook.h"
#include "ClientInstanceHook/ClientInstanceHook.h"
bool HookManager::Initialize() {
	logF("Initializing hooks");
	MH_Initialize();
	{
		add(new SystemHook::FreeLibraryFn());
		add(new ClientInstanceHook::update());
		add(new LocalPlayerHook::normalTick());
		add(new MobHook::getCurrentSwingDuration());
	}
	MH_EnableHook(MH_ALL_HOOKS);
	logF("Initialized hooks");
	return true;
}

bool HookManager::Restore() {
	logF("Deleting hooks");
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