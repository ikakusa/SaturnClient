#pragma once
#include "../HookManager.h"
#include <DX11/DirectX11.h>

class DirectXHook {
public:
	static inline bool isInitialized = false;
public:
	static bool Initialize();
	static void shutdown() {
		DX11::shutdown();
	}
};