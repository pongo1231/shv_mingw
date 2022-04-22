# shv_mingw

A replacement for Scripthook's provided static library to allow compilation with MinGW.

This simply calls the corresponding exported symbol with `GetProcAddress` in `ScriptHookV.dll` for each function.

Note that not all the functionality was tested, however the most commonly used functions (`scriptRegister`, `scriptRegisterAdditionalThread`, native calls, `keyboardHandlerRegister` and `keyboardHandlerUnregister`) are working.

# Building

This project uses CMake.
Building should be as simple as:

```
mkdir build
cd build
cmake ..
make
```

# Using it in your own project

Simply link against the resulting `libshv.a`.

Also make sure to replace the `IMPORT` define in Scripthook's `main.h` with an empty one (as it does some fuckery to the symbol names).
