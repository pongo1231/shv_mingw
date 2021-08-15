#define WIN32_LEAN_AND_MEAN
#include "shv/main.h"
#include "shv/natives.h"

#include <windows.h>

bool start_fire = false;

void script_main()
{
    while (true)
    {
        scriptWait(0);

        if (DLC2::GET_IS_LOADING_SCREEN_ACTIVE())
        {
            continue;
        }

        UI::FLASH_MINIMAP_DISPLAY();

        if (start_fire)
        {
            start_fire = false;

            auto veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
            if (veh)
            {
                VEHICLE::SET_VEHICLE_ENGINE_HEALTH(veh, 0.f);
            }
        }
    }
}

void another_script_thread()
{
    while (true)
    {
        scriptWait(1000);

        if (DLC2::GET_IS_LOADING_SCREEN_ACTIVE())
        {
            continue;
        }

        auto veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), false);
        if (veh)
        {
            VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh, 255, 0, 0);
        }
    }
}

void keyboard_handle(DWORD key, WORD repeats, BYTE scanCode, BOOL isExtended, BOOL isWithAlt,
    BOOL wasDownBefore, BOOL isUpNow)
{
    if (key == VK_OEM_COMMA)
    {
        start_fire = true;
    }
}

BOOL WINAPI DllMain(HMODULE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    switch (dwReason)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hInstance);

        scriptRegister(hInstance, script_main);

        scriptRegisterAdditionalThread(hInstance, another_script_thread);

        keyboardHandlerRegister(keyboard_handle);

        break;

    case DLL_PROCESS_DETACH:
        scriptUnregister(hInstance);

        keyboardHandlerUnregister(keyboard_handle);

        break;
    }

    return TRUE;
}