#ifndef PUASM_LANGUAGE_HEADER__
#define PUASM_LANGUAGE_HEADER__

#include <cstdint>

#ifdef WIN32
#ifndef LIBIMPORT
#define LIB_API extern "C" __declspec(dllexport)
#else
#define LIB_API extern "C" __declspec(dllimport)
#endif
#else
#define LIB_API extern "C"
#endif

    LIB_API uint32_t puasm_init();
    LIB_API uint32_t puasm_deinit();


#endif
