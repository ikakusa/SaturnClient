#include "HookManager.h"

#include "ActorHook/ActorHook.h"

bool HookManager::Initialize() {
	{
		add(new LocalPlayerHook::normalTick());
	}
	MH_EnableHook(MH_ALL_HOOKS);
	return true;
}

HookManager* hooks = new HookManager();