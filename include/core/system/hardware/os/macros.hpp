// Abdulkadir U. - 2026/11/24
#pragma once

// Define Architecture
#if defined(_WIN64) || defined(__x86_64__) || defined(__ppc64__)
    #define __ARCH_64__
#elif defined(_WIN32) || defined(__i386__) || defined(__ppc__)
    #define __ARCH_32__
#endif

// Define Platform and Operating System
#if defined(_WIN32) || defined(_WIN64)
    #define __PFM_MSWIN__

    #define __OS_WINDOWS__

    #ifndef WIN32_LEAN_AND_MEAN
        #define WIN32_LEAN_AND_MEAN
    #endif
#elif defined(__linux__)
    #define __PFM_LINUX__

    #define __OS_POSIX__
    #define __OS_LINUX__
#elif defined(__FreeBSD__) || defined(__unix__)
    #define __PFM_UNIX__

    #define __OS_POSIX__
    #define __OS_BSD__
#else
    #error "[ERROR] Platform: UNIX/LINUX/MSWIN"
    #error "[ERROR] Os: BSD/LINUX/WINDOWS"
#endif