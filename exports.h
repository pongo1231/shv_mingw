#pragma once

// Not needed but why not
#ifdef BUILDING
#define DLL_FUNC __declspec(dllexport)
#else
#define DLL_FUNC __declspec(dllimport)
#endif

#define MAXDWORD 0xffffffff

using BYTE = unsigned char;
using WORD = unsigned short;
using BOOL = int; // Why does MinGW define this as an int?!?
using DWORD = unsigned long;
using DWORD64 = unsigned long long;

using UINT64 = DWORD64;
using PUINT64 = DWORD64*;

struct HINSTANCE__;
using HMODULE = HINSTANCE__*;

using PresentCallback = void(*)(void*);
using KeyboardHandler = void(*)(DWORD, WORD, BYTE, BOOL, BOOL, BOOL, BOOL);

DLL_FUNC int createTexture(const char *texFileName);
DLL_FUNC void drawTexture(int id, int index, int level, int time, float sizeX, float sizeY,
    float centerX, float centerY, float posX, float posY, float rotation,
    float screenHeightScaleFactor, float r, float g, float b, float a);

DLL_FUNC void presentCallbackRegister(PresentCallback cb);
DLL_FUNC void presentCallbackUnregister(PresentCallback cb);

DLL_FUNC void keyboardHandlerRegister(KeyboardHandler handler);
DLL_FUNC void keyboardHandlerUnregister(KeyboardHandler handler);

DLL_FUNC void scriptWait(DWORD time);
DLL_FUNC void scriptRegister(HMODULE module, void(*LP_SCRIPT_MAIN)());
DLL_FUNC void scriptRegisterAdditionalThread(HMODULE module, void(*LP_SCRIPT_MAIN)());
DLL_FUNC void scriptUnregister(HMODULE module);

DLL_FUNC void nativeInit(UINT64 hash);
DLL_FUNC void nativePush64(UINT64 val);
DLL_FUNC PUINT64 nativeCall();

DLL_FUNC UINT64 *getGlobalPtr(int globalId);

DLL_FUNC int worldGetAllVehicles(int *arr, int arrSize);
DLL_FUNC int worldGetAllPeds(int *arr, int arrSize);
DLL_FUNC int worldGetAllObjects(int *arr, int arrSize);
DLL_FUNC int worldGetAllPickups(int *arr, int arrSize);

DLL_FUNC BYTE *getScriptHandleBaseAddress(int handle);

enum eGameVersion : int;

DLL_FUNC eGameVersion getGameVersion();
