#include <Libraries.h>
#include <Utils.h>
#include "Hooks/HookManager.h"

HRESULT EjectThread() {
    while (client.isRunning()) {
        Sleep(20);
    }
    Sleep(100);
    hooks->Restore();
    logF("Ejected");
    FreeLibraryAndExitThread(client.getMod(), 1);
    return 1;
}

HRESULT Initialize() {
    Utils::makeFolder();
    Utils::makeAssetsFolder("Logs");
    Utils::makeAssetsFolder("Assets");
    Utils::makeAssetsFolder("Config");
    logF("Folder created\nInitializing");
    client.setRunning(true);
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)EjectThread, 0, 0, 0);
    logF("Created EjectThread");
    hooks->Initialize();
    return 1;
}

BOOL WINAPI DllMain(
    HMODULE hModule,
    DWORD fdwReason,
    LPVOID lpvReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
    {
        client.setMod(hModule);
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Initialize, 0, 0, 0);
    } break;

    case DLL_THREAD_ATTACH:
        break;

    case DLL_THREAD_DETACH:
        break;

    case DLL_PROCESS_DETACH:

        if (lpvReserved != nullptr)
        {
            break;
        }
        break;
    }
    return TRUE;
}