#include <Libraries.h>
#include <Utils.h>
#include "Hooks/HookManager.h"

HRESULT Initialize() {
    Utils::makeFolder();
    MH_Initialize();
    hooks->Initialize();
    return 1;
}

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,
    DWORD fdwReason,
    LPVOID lpvReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
    {
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