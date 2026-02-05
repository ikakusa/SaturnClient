#include "DirectX11.h"
#include <ClientData.h>

void DX11::initImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}

HRESULT DX11::onResizeBuffers(IDXGISwapChain* a1, UINT a2, UINT width, UINT height, DXGI_FORMAT a5, UINT a6) {
	if (mainRenderTargetView) mainRenderTargetView->Release();
	ImFX::CleanupFX();
	return oResizeBuffers(a1, a2, width, height, a5, a6);
}

HRESULT __stdcall DX11::presentCallback(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags) {
	auto guiData = client.getGuiData();
	if (!guiData || !runningDX11) return oPresent(pSwapChain, SyncInterval, Flags);
	static ID3D12Device* d3d12Device = nullptr;
	if (SUCCEEDED(pSwapChain->GetDevice(IID_PPV_ARGS(&d3d12Device)))) {
		static_cast<ID3D12Device5*>(d3d12Device)->RemoveDevice();
	}
	if (SUCCEEDED(pSwapChain->GetDevice(IID_PPV_ARGS(&pDevice))))
	{
		pDevice->GetImmediateContext(&pContext);
		DXGI_SWAP_CHAIN_DESC sd;
		pSwapChain->GetDesc(&sd);

		window = (HWND)FindWindowA(nullptr, (LPCSTR)"Minecraft");

		ID3D11Texture2D* pBackBuffer = nullptr;
		pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
		
		IDXGISurface* dxgiBackBuffer = nullptr;
		pSwapChain->GetBuffer(0, IID_PPV_ARGS(&dxgiBackBuffer));

		pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
		pBackBuffer->Release();
		if (!hasInitImGui)
		{
			initImGui();
			hasInitImGui = true;
		}

		ImFX::NewFrame(pDevice, dxgiBackBuffer, (float)GetDpiForWindow(window));

		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		ImGui::Begin("ImGui Window");
		ImGui::End();
		ImGui::Render();

		pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

		ImFX::EndFrame();
		pContext->Flush();
		pContext->Release();
		if (mainRenderTargetView) mainRenderTargetView->Release();
		pDevice->Release();
	}
	else {
		return oPresent(pSwapChain, SyncInterval, Flags);

	}
	return oPresent(pSwapChain, SyncInterval, Flags);
}

void DX11::shutdown() {
	runningDX11 = false;
	ImFX::CleanupFX();
	kiero::shutdown();
	if (ImGui::GetCurrentContext()) {
		if (pContext) pContext->Release();
		if (pDevice) pDevice->Release();
		ImGui_ImplDX11_Shutdown();
		ImGui_ImplWin32_Shutdown();
		ImGui::Shutdown();
	}
}