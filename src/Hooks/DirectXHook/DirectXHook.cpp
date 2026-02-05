#include "DirectXHook.h"

bool DirectXHook::Initialize() {
	if (!isInitialized) {
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success) {
			kiero::bind(8, (void**)&DX11::oPresent, DX11::presentCallback);
			kiero::bind(13, (void**)&DX11::oResizeBuffers, DX11::onResizeBuffers);
			isInitialized = true;
			DX11::runningDX11 = true;
		}
	}
	return isInitialized;
}