cmake_minimum_required (VERSION 3.10)
project (McDonalds LANGUAGES CXX)
include(FetchContent)
set(CMAKE_CXX_STANDARD 20)
add_library(${PROJECT_NAME} SHARED
    "src/dllmain.cpp"
    "src/Libraries/Libraries.h"
    "src/Utils/Utils.h" "src/Utils/Utils.cpp"
 "src/Utils/ClientData.h" "src/Utils/ClientData.cpp" "src/Utils/MemUtils.h" "src/Hooks/HookManager.cpp"
 "src/Hooks/ActorHook/ActorHook.h")

target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_SOURCE_DIR}/src/Libraries"
    "${CMAKE_SOURCE_DIR}/src/Utils"
)

target_sources(${PROJECT_NAME} PUBLIC
    "src"
 "src/Hooks/ActorHook/ActorHook.h")

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