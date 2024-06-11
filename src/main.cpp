#include "main.hpp"

std::ofstream logFile;

DWORD WINAPI GuiThread(LPVOID hModule) {
    logFile.open("GuiThread.txt");

    if (logFile.is_open()) {
        logFile << "Starting Gui Thread" << std::endl;

        uintptr_t moduleBaseAddress = reinterpret_cast<uintptr_t>(GetModuleHandle(L"eldenring.exe"));

        logFile << "Found module base address at: " << moduleBaseAddress << std::endl;

        while (true) {
            if (GetAsyncKeyState(VK_END) & 1) {
                break;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Prevents CPU overuse
        }

        logFile << "Exiting Gui Thread" << std::endl;
        logFile.close();
    } else {
        MessageBoxA(nullptr, "Failed to open log file.", "Error", MB_OK | MB_ICONERROR);
    }

    // fclose(f);
    // FreeConsole();
    FreeLibraryAndExitThread(static_cast<HMODULE>(hModule), 0);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD ul_reason_for_call,
                      LPVOID lpReserved
) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH: {
            DisableThreadLibraryCalls(hModule);
            HANDLE hThread = CreateThread(nullptr, 0, GuiThread, hModule, 0, nullptr);
            if (hThread) {
                CloseHandle(hThread);
            }
            break;
        }

        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}
