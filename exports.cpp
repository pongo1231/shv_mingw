#define BUILDING
#include "exports.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define PROC_EXEC(proc, type, ...) \
    do \
    { \
        static auto addr = GetProcAddress(shv_mod, proc); \
        if (addr) \
        { \
            reinterpret_cast<type>(addr)(__VA_ARGS__); \
        } \
    } \
    while (0);

#define PROC_EXEC_RET(proc, type, ...) \
    do \
    { \
        static auto addr = GetProcAddress(shv_mod, proc); \
        if (addr) \
        { \
            return reinterpret_cast<type>(addr)(__VA_ARGS__); \
        } \
    } \
    while (0);

HMODULE shv_mod = NULL;

int createTexture(const char* texFileName)
{
    PROC_EXEC_RET("?createTexture@@YAHPEBD@Z", int(*)(const char*), texFileName);

    return 0;
}

void drawTexture(int id, int index, int level, int time, float sizeX, float sizeY,
    float centerX, float centerY, float posX, float posY, float rotation,
    float screenHeightScaleFactor, float r, float g, float b, float a)
{
    PROC_EXEC("?drawTexture@@YAXHHHHMMMMMMMMMMMM@Z", void(*)(int, int, int, int, float, float, float,
        float, float, float, float, float, float, float, float, float), id, index, level, time,
        sizeX, sizeY, centerX, centerY, posX, posY, rotation, screenHeightScaleFactor, r, g, b, a);
}

void presentCallbackRegister(PresentCallback cb)
{
    PROC_EXEC("?presentCallbackRegister@@YAXP6AXPEAX@Z@Z", void(*)(PresentCallback), cb);
}

void presentCallbackUnregister(PresentCallback cb)
{
    PROC_EXEC("?presentCallbackUnregister@@YAXP6AXPEAX@Z@Z", void(*)(PresentCallback), cb);
}

void keyboardHandlerRegister(KeyboardHandler handler)
{
    PROC_EXEC("?keyboardHandlerRegister@@YAXP6AXKGEHHHH@Z@Z", void(*)(KeyboardHandler), handler);
}

void keyboardHandlerUnregister(KeyboardHandler handler)
{
    PROC_EXEC("?keyboardHandlerUnregister@@YAXP6AXKGEHHHH@Z@Z", void(*)(KeyboardHandler), handler);
}

void scriptWait(DWORD time)
{
    PROC_EXEC("?scriptWait@@YAXK@Z", void(*)(DWORD), time);
}

void scriptRegister(HMODULE module, void(*LP_SCRIPT_MAIN)())
{
    if (!shv_mod)
    {
        shv_mod = LoadLibrary(L"ScriptHookV.dll");
    }

    PROC_EXEC("?scriptRegister@@YAXPEAUHINSTANCE__@@P6AXXZ@Z", void(*)(HMODULE, void(*)(void)),
        module, LP_SCRIPT_MAIN);
}

void scriptRegisterAdditionalThread(HMODULE module, void(*LP_SCRIPT_MAIN)())
{
    PROC_EXEC("?scriptRegisterAdditionalThread@@YAXPEAUHINSTANCE__@@P6AXXZ@Z",
        void(*)(HINSTANCE, void(*)(void)), module, LP_SCRIPT_MAIN);
}

void scriptUnregister(HMODULE module)
{
    PROC_EXEC("?scriptUnregister@@YAXPEAUHINSTANCE__@@@Z", void(*)(HMODULE), module);
}

void nativeInit(UINT64 hash)
{
    PROC_EXEC("?nativeInit@@YAX_K@Z", void(*)(UINT64), hash);
}

void nativePush64(UINT64 val)
{
    PROC_EXEC("?nativePush64@@YAX_K@Z", void(*)(UINT64), val);
}

PUINT64 nativeCall()
{
    PROC_EXEC_RET("?nativeCall@@YAPEA_KXZ", PUINT64(*)(void));

    return 0;
}

UINT64 *getGlobalPtr(int globalId)
{
    PROC_EXEC_RET("?getGlobalPtr@@YAPEA_KH@Z", UINT64*(*)(int), globalId);

    return nullptr;
}

int worldGetAllVehicles(int* arr, int arrSize)
{
    PROC_EXEC_RET("?worldGetAllVehicles@@YAHPEAHH@Z", int(*)(int*, int), arr, arrSize);

    return 0;
}

int worldGetAllPeds(int* arr, int arrSize)
{
    PROC_EXEC_RET("?worldGetAllPeds@@YAHPEAHH@Z", int(*)(int*, int), arr, arrSize);

    return 0;
}

int worldGetAllObjects(int* arr, int arrSize)
{
    PROC_EXEC_RET("?worldGetAllObjects@@YAHPEAHH@Z", int(*)(int*, int), arr, arrSize);

    return 0;
}

int worldGetAllPickups(int* arr, int arrSize)
{
    PROC_EXEC_RET("?worldGetAllPickups@@YAHPEAHH@Z", int(*)(int*, int), arr, arrSize);

    return 0;
}

BYTE *getScriptHandleBaseAddress(int handle)
{
    PROC_EXEC_RET("?getScriptHandleBaseAddress@@YAPEAEH@Z", BYTE*(*)(int), handle);

    return nullptr;
}

eGameVersion getGameVersion()
{
    PROC_EXEC_RET("?getGameVersion@@YA?AW4eGameVersion@@XZ", eGameVersion(*)(void));

    return static_cast<eGameVersion>(-1);
}