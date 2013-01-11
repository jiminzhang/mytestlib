#if !defined(__CONFIG_HEADER_H__)
#define __CONFIG_HEADER_H__

// os relative
#if defined(__MACOSX__) || (defined(__APPLE__) && defined(__MACH__))
# define OS_MACOSX
#endif

#if defined(linux) || defined(__linux) || defined(__linux__)
# define OS_LINUX_KERNEL
#endif

#if defined(OS_LINUX_KERNEL) && defined(__ANDROID__)
#define OS_ANDROID
#endif

#if defined(OS_LINUX_KERNEL) && !defined(__ANDROID__)
#define OS_LINUX
#endif

#if defined(WIN32) || defined(_WIN32)
#define OS_WIN
#endif

#if defined(__CYGWIN__)
#define OS_CYGWIN
#endif

#if defined(unix) || defined(__unix) || defined(__unix__) // linux no define this
#define OS_UNIX
#endif
// compiler relative
/*
 * MinGW32
 */
#if defined(__MINGW32__)
#define CC_MINGW32
#endif

#if defined(_MSC_VER)
#define CC_MSVC
#endif

#if defined(__clang__)
#define CC_CLANG
#endif

#if defined(__GNUC__)
#define CC_GCC
#endif

// language
// #if defined(__cplusplus)

#if defined(OS_LINUX) || defined(OS_UINX) || defined(OS_MACOSX)
#include <unistd.h>
#endif

#if defined(OS_WIN)
#include <windows.h>
#endif



// basic type defines
typedef unsigned char       u8;
typedef signed char     s8;

typedef char            c8;// char 
typedef char            b8;// boolean

typedef unsigned short      u16;
typedef signed short        s16;

typedef unsigned int        u32;
typedef signed int      s32;

typedef unsigned long long          u64;
typedef long long               s64;

typedef float               f32;
typedef double              f64;


// config
#define ENABLE_LOG
#endif