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
 "src/Libraries/imgui/imgui.h" "src/Libraries/imgui/imgui.cpp" "src/Libraries/imgui/imconfig.h" "src/Libraries/imgui/imgui_demo.cpp" "src/Libraries/imgui/imgui_draw.cpp" "src/Libraries/imgui/imgui_internal.h" "src/Libraries/imgui/imgui_tables.cpp" "src/Libraries/imgui/imgui_widgets.cpp" "src/Libraries/imgui/imstb_rectpack.h" "src/Libraries/imgui/imstb_textedit.h" "src/Libraries/imgui/imstb_truetype.h" "src/SDK/Core/MinecraftGame.h" "src/SDK/Core/Minecraft.h" "src/Hooks/DirectXHook/DirectXHook.cpp" "src/Libraries/imgui/imgui_impl_win32.h" "src/Libraries/imgui/imgui_impl_win32.cpp" "src/Libraries/imgui/imgui_impl_dx11.h" "src/Libraries/imgui/imgui_impl_dx11.cpp" "src/SDK/DX11/DirectX11.cpp" "src/Libraries/ImFX/ImFX.h" "src/Libraries/ImFX/ImFX.cpp" "src/Hooks/ScreenContextHook/ScreenContextHook.h" "src/SDK/Core/ScreenContext.h" "src/Utils/AnimationUtils.h" "src/Utils/Animations/easeOutBounce.h" "src/Utils/Animations/easeBase.h" "src/Hooks/OptionsHook/OptionsHook.h" "src/SDK/GameMode/GameMode.h" "src/SDK/Inventory/PlayerInventory.h" "src/SDK/Item/ItemStack.h" "src/SDK/Item/Item.h" "src/SDK/Item/ItemStackBase.h" "src/SDK/CompoundTag/CompoundTag.h" "src/SDK/Inventory/Inventory.h" "src/SDK/Packet/Packet.h" "src/SDK/Packet/PayloadPacket.h" "src/SDK/Packet/Payloads/TextPacketPayload.h" "src/Utils/Animations/easeInSine.h" "src/Utils/Animations/easeOutSine.h" "src/Utils/Animations/easeInOutSine.h" "src/Utils/Animations/easeInCubic.h" "src/Utils/Animations/easeOutCubic.h" "src/Utils/Animations/easeInOutCubic.h" "src/Hooks/ConnectionRequestHook/ConcreHook.h" "src/Hooks/LoopBackPacketSender/LoopbackPacketSender.h" "src/SDK/Core/LoopbackPacketSender.h" "src/SDK/Packet/Payloads/RequestPermissionPayload.h" "src/SDK/Packet/TextPacket.h" "src/SDK/Packet/RequestPermissions.h" "src/Utils/Animations/easeInQuint.h" "src/Utils/Animations/easeInOutQuint.h" "src/Utils/Animations/easeInCirc.h" "src/Utils/Animations/easeOutCirc.h" "src/Utils/Animations/easeInOutCirc.h" "src/Utils/Animations/easeInElastic.h" "src/Utils/Animations/easeOutElastic.h" "src/Utils/Animations/easeInOutElastic.h" "src/Utils/Animations/easeInQuad.h" "src/Utils/Animations/easeInOutQuad.h" "src/Utils/Animations/easeOutQuad.h" "src/Utils/Animations/easeInQuart.h" "src/Utils/Animations/easeInOutQuart.h" "src/Utils/Animations/easeOutQuart.h" "src/Utils/Animations/easeInExpo.h" "src/Utils/Animations/easeOutExpo.h" "src/Utils/Animations/easeInOutExpo.h" "src/Utils/Animations/easeInBack.h" "src/Utils/Animations/easeOutBack.h" "src/Utils/Animations/easeInBounce.h" "src/Utils/Animations/easeInOutBounce.h")

target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_SOURCE_DIR}/src/Libraries"
    "${CMAKE_SOURCE_DIR}/src/Utils"
    "${CMAKE_SOURCE_DIR}/src/SDK"
)

target_sources(${PROJECT_NAME} PUBLIC
    "src"
 "src/Hooks/ActorHook/ActorHook.h" "src/SDK/Actor/Actor.h" "src/SDK/Actor/Player.h" "src/SDK/Actor/LocalPlayer.h" "src/SDK/Actor/LocalPlayer.cpp" "src/SDK/Actor/Mob.h" "src/Hooks/SystemHook/SystemHook.h" "src/SDK/Core/ClientInstance.h" "src/SDK/Core/GuiData.h" "src/Hooks/ClientInstanceHook/ClientInstanceHook.h" "src/SDK/Actor/Level.h" "src/Utils/MathUtils.h" "src/SDK/Actor/Components/StateVectorComponent.h" "src/SDK/Actor/Components/RotationComponent.h" "src/Libraries/Kiero/kiero.h" "src/Libraries/Kiero/kiero.cpp" "src/Hooks/DirectXHook/DirectXHook.h" "src/SDK/DX11/DirectX11.h"
"src/Libraries/imgui/imgui.h" "src/Libraries/imgui/imgui.cpp" "src/Libraries/imgui/imconfig.h" "src/Libraries/imgui/imgui_demo.cpp" "src/Libraries/imgui/imgui_draw.cpp" "src/Libraries/imgui/imgui_internal.h" "src/Libraries/imgui/imgui_tables.cpp" "src/Libraries/imgui/imstb_rectpack.h" "src/Libraries/imgui/imstb_textedit.h" "src/Libraries/imgui/imstb_truetype.h" "src/SDK/Core/MinecraftGame.h" "src/SDK/Core/Minecraft.h" "src/Hooks/DirectXHook/DirectXHook.cpp" "src/Libraries/imgui/imgui_impl_win32.h" "src/Libraries/imgui/imgui_impl_win32.cpp" "src/Libraries/imgui/imgui_impl_dx11.h" "src/Libraries/imgui/imgui_impl_dx11.cpp" "src/SDK/DX11/DirectX11.cpp" "src/Libraries/ImFX/ImFX.h" "src/Libraries/ImFX/ImFX.cpp" "src/Hooks/ScreenContextHook/ScreenContextHook.h" "src/SDK/Core/ScreenContext.h" "src/Utils/AnimationUtils.h" "src/Utils/Animations/easeOutBounce.h" "src/Utils/Animations/easeBase.h" "src/Hooks/OptionsHook/OptionsHook.h" "src/SDK/GameMode/GameMode.h" "src/SDK/Inventory/PlayerInventory.h" "src/SDK/Item/ItemStack.h" "src/SDK/Item/Item.h" "src/SDK/Item/ItemStackBase.h" "src/SDK/CompoundTag/CompoundTag.h" "src/SDK/Inventory/Inventory.h" "src/SDK/Packet/Packet.h" "src/SDK/Packet/PayloadPacket.h" "src/SDK/Packet/Payloads/TextPacketPayload.h" "src/Utils/Animations/easeInSine.h" "src/Utils/Animations/easeOutSine.h" "src/Utils/Animations/easeInOutSine.h" "src/Utils/Animations/easeInCubic.h" "src/Utils/Animations/easeOutCubic.h" "src/Utils/Animations/easeInOutCubic.h" "src/Hooks/ConnectionRequestHook/ConcreHook.h" "src/Hooks/LoopBackPacketSender/LoopbackPacketSender.h" "src/SDK/Core/LoopbackPacketSender.h" "src/SDK/Packet/Payloads/RequestPermissionPayload.h" "src/SDK/Packet/TextPacket.h" "src/SDK/Packet/RequestPermissions.h" "src/Utils/Animations/easeInQuint.h" "src/Utils/Animations/easeInOutQuint.h" "src/Utils/Animations/easeInCirc.h" "src/Utils/Animations/easeOutCirc.h" "src/Utils/Animations/easeInOutCirc.h" "src/Utils/Animations/easeInElastic.h" "src/Utils/Animations/easeOutElastic.h" "src/Utils/Animations/easeInOutElastic.h" "src/Utils/Animations/easeInQuad.h" "src/Utils/Animations/easeInOutQuad.h" "src/Utils/Animations/easeOutQuad.h" "src/Utils/Animations/easeInQuart.h" "src/Utils/Animations/easeInOutQuart.h" "src/Utils/Animations/easeOutQuart.h" "src/Utils/Animations/easeInExpo.h" "src/Utils/Animations/easeOutExpo.h" "src/Utils/Animations/easeInOutExpo.h" "src/Utils/Animations/easeInBack.h" "src/Utils/Animations/easeOutBack.h" "src/Utils/Animations/easeInBounce.h" "src/Utils/Animations/easeInOutBounce.h")

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