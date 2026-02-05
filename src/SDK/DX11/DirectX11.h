#pragma once
#include <dxgi.h>
#include <d3d11.h>
#include <d3d12.h>
#include "Kiero/kiero.h"
#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "imgui/imgui_impl_dx11.h"
#include "imgui/imgui_impl_win32.h"
#include "ImFX/ImFX.h"

typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef HRESULT(__thiscall* OriginResizeBuffer)(IDXGISwapChain*, UINT, UINT, UINT, DXGI_FORMAT, UINT);

class ClientData;
extern ClientData client;

class DX11 {
public:
	static inline bool hasInitImGui = false;
	static inline bool runningDX11 = false;
public:
	static inline Present oPresent = nullptr;
	static inline OriginResizeBuffer oResizeBuffers = nullptr;
	static inline HWND window = NULL;
	static inline ID3D11Device* pDevice = nullptr;
	static inline ID3D11DeviceContext* pContext = nullptr;
	static inline ID3D11RenderTargetView* mainRenderTargetView = nullptr;
public:
	static void initImGui();
	static HRESULT __stdcall presentCallback(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
	static HRESULT onResizeBuffers(IDXGISwapChain*, UINT, UINT, UINT, DXGI_FORMAT, UINT);
	static void shutdown();
};