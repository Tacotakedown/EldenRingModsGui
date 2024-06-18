//
// Created by Taco on 6/16/2024.
//

#ifndef DX12HOOK_H
#define DX12HOOK_H


namespace d3dx12hook {
    typedef long (__fastcall*PresentD3D12)(IDXGISwapChain *pSwapChaing, UINT SyncInterval, UINT Flags);

    extern PresentD3D12 oPresentD3D12;

    typedef void (__fastcall*DrawInstanceD3D12)(ID3D12GraphicsCommandList *dCommandList, UINT VertextCountPerInsance,
                                                UINT InstanceCount, UINT StartVertexLocation,
                                                UINT StartInstanceLocation);

    extern DrawInstanceD3D12 oDrawIncancedD3D12;

    typedef void (__fastcall*DrawIndexedInstanceD3D12)(ID3D12GraphicsCommandList *dCommandList, UINT IndexCount,
                                                       UINT InstanceCount, UINT StartIndex, UINT BaseVertex);

    extern DrawIndexedInstanceD3D12 oDrawIndexedInstancedD3D12;

    extern void (*oExecuteCommandLists)(ID3D12CommandQueue *, UINT, ID3D12CommandList *);

    extern HRESULT (*oSignalD3D12)(ID3D12CommandQueue *, ID3D12Fence *, UINT64);

    extern long __fastcall hookPresentD3D12(IDXGISwapChain3 *pSwapChain, UINT SyncInterval, UINT Flags);

    extern void __fastcall hookDrawInstancedD3D12(ID3D12GraphicsCommandList *dCommandList, UINT VertexCountPerInstance,
                                                  UINT InstanceCount, UINT StartVertexLocation,
                                                  UINT StartInstanceLocation);

    extern void __fastcall hookDrawIndexedInstancedD3D12(ID3D12GraphicsCommandList *dCommandList, UINT IndexCount,
                                                         UINT InstanceCount, UINT StartIndex, UINT BaseVertex);

    extern void hookExecuteCommandListsD3D12(ID3D12CommandQueue *queue, UINT NumCommandLists,
                                             ID3D12CommandList *ppCommandLists);

    extern HRESULT hookSignalD3D12(ID3D12CommandQueue *queue, ID3D12Fence *fence, UINT64 value);

    extern void release();
}

#endif //DX12HOOK_H
