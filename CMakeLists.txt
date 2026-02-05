cmake_minimum_required (VERSION 3.10)
project (McDonalds LANGUAGES CXX)
include(FetchContent)
set(CMAKE_CXX_STANDARD 20)
add_library(${PROJECT_NAME} SHARED
    "src/dllmain.cpp"
    "src/Libraries/Libraries.h"
    "src/Utils/Utils.h" "src/Utils/Utils.cpp"
 "src/Utils/ClientData.h" "src/Utils/ClientData.cpp" "src/Utils/MemUtils.h" "src/Hooks/HookManager.cpp"
 "src/Hooks/ActorHook/ActorHook.h" "src/SDK/Actor/Actor.h" "src/SDK/Actor/Player.h" "src/SDK/Actor/LocalPlayer.h" "src/SDK/Actor/LocalPlayer.cpp" "src/SDK/Actor/Mob.h" "src/Hooks/SystemHook/SystemHook.h" "src/SDK/Core/ClientInstance.h" "src/SDK/Core/GuiData.h" "src/Hooks/ClientInstanceHook/ClientInstanceHook.h" "src/SDK/Actor/Level.h" "src/Utils/MathUtils.h" "src/SDK/Actor/Components/StateVectorComponent.h" "src/SDK/Actor/Components/RotationComponent.h" "src/Libraries/Kiero/kiero.h" "src/Libraries/Kiero/kiero.cpp" "src/Hooks/DirectXHook/DirectXHook.h" "src/SDK/DX11/DirectX11.h"
 "src/Libraries/imgui/imgui.h" "src/Libraries/imgui/imgui.cpp" "src/Libraries/imgui/imconfig.h" "src/Libraries/imgui/imgui_demo.cpp" "src/Libraries/imgui/imgui_draw.cpp" "src/Libraries/imgui/imgui_internal.h" "src/Libraries/imgui/imgui_tables.cpp" "src/Libraries/imgui/imgui_widgets.cpp" "src/Libraries/imgui/imstb_rectpack.h" "src/Libraries/imgui/imstb_textedit.h" "src/Libraries/imgui/imstb_truetype.h" "src/SDK/Core/MinecraftGame.h" "src/SDK/Core/Minecraft.h" "src/Hooks/DirectXHook/DirectXHook.cpp" "src/Libraries/imgui/imgui_impl_win32.h" "src/Libraries/imgui/imgui_impl_win32.cpp" "src/Libraries/imgui/imgui_impl_dx11.h" "src/Libraries/imgui/imgui_impl_dx11.cpp" "src/SDK/DX11/DirectX11.cpp" "src/Libraries/ImFX/ImFX.h" "src/Libraries/ImFX/ImFX.cpp" "src/Hooks/ScreenContextHook/ScreenContextHook.h" "src/SDK/Core/ScreenContext.h")

target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_SOURCE_DIR}/src/Libraries"
    "${CMAKE_SOURCE_DIR}/src/Utils"
    "${CMAKE_SOURCE_DIR}/src/SDK"
)

target_sources(${PROJECT_NAME} PUBLIC
    "src"
 "src/Hooks/ActorHook/ActorHook.h" "src/SDK/Actor/Actor.h" "src/SDK/Actor/Player.h" "src/SDK/Actor/LocalPlayer.h" "src/SDK/Actor/LocalPlayer.cpp" "src/SDK/Actor/Mob.h" "src/Hooks/SystemHook/SystemHook.h" "src/SDK/Core/ClientInstance.h" "src/SDK/Core/GuiData.h" "src/Hooks/ClientInstanceHook/ClientInstanceHook.h" "src/SDK/Actor/Level.h" "src/Utils/MathUtils.h" "src/SDK/Actor/Components/StateVectorComponent.h" "src/SDK/Actor/Components/RotationComponent.h" "src/Libraries/Kiero/kiero.h" "src/Libraries/Kiero/kiero.cpp" "src/Hooks/DirectXHook/DirectXHook.h" "src/SDK/DX11/DirectX11.h"
"src/Libraries/imgui/imgui.h" "src/Libraries/imgui/imgui.cpp" "src/Libraries/imgui/imconfig.h" "src/Libraries/imgui/imgui_demo.cpp" "src/Libraries/imgui/imgui_draw.cpp" "src/Libraries/imgui/imgui_internal.h" "src/Libraries/imgui/imgui_tables.cpp" "src/Libraries/imgui/imstb_rectpack.h" "src/Libraries/imgui/imstb_textedit.h" "src/Libraries/imgui/imstb_truetype.h" "src/SDK/Core/MinecraftGame.h" "src/SDK/Core/Minecraft.h" "src/Hooks/DirectXHook/DirectXHook.cpp" "src/Libraries/imgui/imgui_impl_win32.h" "src/Libraries/imgui/imgui_impl_win32.cpp" "src/Libraries/imgui/imgui_impl_dx11.h" "src/Libraries/imgui/imgui_impl_dx11.cpp" "src/SDK/DX11/DirectX11.cpp" "src/Libraries/ImFX/ImFX.h" "src/Libraries/ImFX/ImFX.cpp" "src/Hooks/ScreenContextHook/ScreenContextHook.h" "src/SDK/Core/ScreenContext.h")

if(MSVC)
    add_compile_definitions(
        _ITERATOR_DEBUG_LEVEL=0
        _HAS_ITERATOR_DEBUGGING=0
    )
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif()

FetchContent_Declare(
    libhat
    GIT_REPOSITORY https://github.com/BasedInc/libhat.git
    GIT_TAG        v0.9.0
)
FetchContent_MakeAvailable(libhat)

target_link_libraries(${PROJECT_NAME} PUBLIC 
    libhat::libhat
    ${CMAKE_SOURCE_DIR}/src/Libraries/MinHook/libMinHook.x64.lib
)