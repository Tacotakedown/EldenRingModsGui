cmake_minimum_required(VERSION 3.10)
project(Ascendancy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(
        dependencies/ImGui
        dependencies/MinHook/Src
        src
)

add_library(ImGui STATIC
        dependencies/ImGui/imgui.cpp
        dependencies/ImGui/imgui_demo.cpp
        dependencies/ImGui/imgui_draw.cpp
        dependencies/ImGui/imgui_impl_dx10.cpp
        dependencies/ImGui/imgui_impl_dx11.cpp
        dependencies/ImGui/imgui_impl_dx12.cpp
        dependencies/ImGui/imgui_impl_dx9.cpp
        dependencies/ImGui/imgui_impl_win32.cpp
        dependencies/ImGui/imgui_tables.cpp
        dependencies/ImGui/imgui_widgets.cpp
)

target_include_directories(ImGui PUBLIC dependencies/ImGui)

add_library(MinHook STATIC
        dependencies/MinHook/Src/buffer.c
        dependencies/MinHook/Src/hde/hde32.c
        dependencies/MinHook/Src/hde/hde64.c
        dependencies/MinHook/Src/hook.c
        dependencies/MinHook/Src/trampoline.c
)

target_include_directories(MinHook PUBLIC dependencies/MinHook/Src dependencies/MinHook/include)

add_library(Ascendancy SHARED
        src/main.cpp
        src/DirectX12.h
        src/Global.h
        src/main.h
        src/menu/menu.h
        src/menu/menu.cpp
        src/menu/Arial.h
        src/hook/DX12Hook.h
        src/hook/DX12Hook.cpp
        src/stdafx.h
        src/globals/Globals.cpp
        src/globals/Globals.h
)

target_link_libraries(Ascendancy ImGui MinHook)