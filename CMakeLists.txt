cmake_minimum_required(VERSION 3.10)
project(EldenRingModGui)

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

add_library(EldenRingModGui SHARED
        src/main.cpp
        src/DirectX12.h
        src/Global.h
        src/main.h
)

target_link_libraries(EldenRingModGui ImGui MinHook)