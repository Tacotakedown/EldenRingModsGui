//
// Created by Taco on 6/16/2024.
//

#include "stdafx.h"


namespace d3dx12hook {
    ID3D12Device *d3d12Device = nullptr;
    ID3D12DescriptorHeap *d3d12DescriptorHeapBackBuffers = nullptr;
    ID3D12DescriptorHeap *d3d12DescriptorHeapImGuiBuffers = nullptr;
    ID3D12GraphicsCommandList *d3d12CommandList = nullptr;
    ID3D12Fence *d3d12Fence = nullptr;
    UINT64 d3d12FenceValue = 0;
    ID3D12CommandQueue *d3d12CommandQueue = nullptr;

    PresentD3D12 oPresentD3D12;
    DrawInstanceD3D12 oDrawInstancedD3D12;
    DrawIndexedInstanceD3D12 oDrawIndexedInstancedD3D12;

    void (*oExecuteCommandListsD3D12)(ID3D12CommandQueue *, UINT, ID3D12CommandList *);

    HRESULT (*oSignalD3D12)(ID3D12CommandQueue *, ID3D12Fence *, UINT64);

    struct __declspec(uuid("189819f1-1db6-4b57-be54-1821339b85f7")) ID3D12Device;

    struct FrameContext {
        ID3D12CommandAllocator *commandAllocator = nullptr;
        ID3D12Resource *main_render_target_resouce = nullptr;
        D3D12_CPU_DESCRIPTOR_HANDLE main_render_target_descriptor;
    };

    uintx_t buffersCounts = -1;
    FrameContext *frameContext;

    bool shutdown = false;

    long __fastcall hookPresentD3D12(IDXGISwapChain3 *pSwapChain, UINT SyncInterval, UINT Flags) {
        static bool init = false;


        if (!init) {
            if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D12Device), reinterpret_cast<void**>(&d3d12Device)))) {
                ImGui::CreateContext();

                unsigned char *pixels;
                int width, height;
                ImGuiIO &io = ImGui::GetIO();
                static_cast<void>(io);
                ImGui::StyleColorsDark();

                // good place for fonts

                io.IniFilename = nullptr;

                CreateEvent(nullptr, false, false, nullptr);

                DXGI_SWAP_CHAIN_DESC sDescription;
                pSwapChain->GetDesc(&sDescription);
                sDescription.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
                sDescription.OutputWindow = Globals::mainWindow;
                sDescription.Windowed = ((GetWindowLongPtr(Globals::mainWindow, GWL_STYLE) & WS_POPUP) != 0)
                                            ? false
                                            : true;

                buffersCounts = sDescription.BufferCount;
                frameContext = new FrameContext[buffersCounts];

                D3D12_DESCRIPTOR_HEAP_DESC descriptorImGuiRenderer = {};
                descriptorImGuiRenderer.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
                descriptorImGuiRenderer.NumDescriptors = buffersCounts;
                descriptorImGuiRenderer.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

                if (d3d12Device->CreateDescriptorHeap(&descriptorImGuiRenderer,
                                                      IID_PPV_ARGS(&d3d12DescriptorHeapImGuiBuffers)) != S_OK)
                    return false;

                ID3D12CommandAllocator *allocator;
                if (d3d12Device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&allocator)) !=
                    S_OK)
                    return false;

                for (size_t i = 0; i < buffersCounts; i++) {
                    frameContext[i].commandAllocator = allocator;
                }

                if (d3d12Device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, allocator, NULL,
                                                   IID_PPV_ARGS(&d3d12CommandList)) != S_OK || d3d12CommandList->Close()
                    != S_OK)
                    return false;
            }
        }
    }
}
