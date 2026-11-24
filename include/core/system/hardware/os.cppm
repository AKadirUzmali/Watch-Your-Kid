// Abdulkadir U. - 2026/11/24
module;

// Include
#include <cstdint>
#include <format>
#include <string>
#include <string_view>

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

    #include <sys/utsname.h>
#elif defined(__FreeBSD__) || defined(__unix__)
    #define __PFM_UNIX__

    #define __OS_POSIX__
    #define __OS_BSD__

    #include <sys/utsname.h>
#else
    #error "[ERROR] Platform: UNIX/LINUX/MSWIN"
    #error "[ERROR] Os: BSD/LINUX/WINDOWS"
#endif

// Module
export module core.sys.hardware.os;

// Namespace
namespace core::sys::hardware::os
{
    // Enum - Architecture
    export enum class Arch : std::uint8_t
    {
        Unknown = 0,
        Bit32,
        Bit64
    };

    // Enum - Platform
    export enum class Platform : std::uint8_t
    {
        Unknown = 0,
        MsWin,
        Linux,
        Unix
    };

    // Enum - Operating System
    export enum class Os : std::uint8_t
    {
        Unknown = 0,
        Windows,
        Linux,
        Bsd
    };

    #if defined(__ARCH_64__)
        constexpr bool arch_64 = true;
        constexpr bool arch_32 = false;
    #elif defined(__ARCH_32__)
        constexpr bool arch_64 = false;
        constexpr bool arch_32 = true;
    #else
        constexpr bool arch_64 = false;
        constexpr bool arch_32 = false;
    #endif

    #if defined(__PFM_MSWIN__)
        constexpr bool pfm_mswin = true;
        constexpr bool pfm_linux = false;
        constexpr bool pfm_unix = false;
    #elif defined(__PFM_LINUX__)
        constexpr bool pfm_mswin = false;
        constexpr bool pfm_linux = true;
        constexpr bool pfm_unix = false;
    #elif defined(__PFM_UNIX__)
        constexpr bool pfm_mswin = false;
        constexpr bool pfm_linux = false;
        constexpr bool pfm_unix = true;
    #else
        constexpr bool pfm_mswin = false;
        constexpr bool pfm_linux = false;
        constexpr bool pfm_unix = false;
    #endif

    #if defined(__OS_WINDOWS__)
        constexpr bool os_windows = true;
        constexpr bool os_linux   = false;
        constexpr bool os_bsd     = false;
    #elif defined(__OS_LINUX__)
        constexpr bool os_windows = false;
        constexpr bool os_linux   = true;
        constexpr bool os_bsd     = false;
    #elif defined(__OS_BSD__)
        constexpr bool os_windows = false;
        constexpr bool os_linux   = false;
        constexpr bool os_bsd     = true;
    #else
        constexpr bool os_windows = false;
        constexpr bool os_linux   = false;
        constexpr bool os_bsd     = false;
    #endif

    // Preprocessor
    export [[nodiscard]] constexpr Arch get_arch() noexcept;
    export [[nodiscard]] consteval Platform get_platform() noexcept;
    export [[nodiscard]] consteval Os get_os() noexcept;
    export [[nodiscard]] std::string get_version() noexcept;

    /**
     * @brief Get Arch
     * 
     * İşletim sisteminin mimarisini bulur ve enum olarak döndürür
     *
     * @return Arch
     */
    [[nodiscard]] constexpr Arch get_arch() noexcept
    {
        if constexpr (arch_64)
            return Arch::Bit64;
        else if constexpr (arch_32)
            return Arch::Bit32;
        else
            return Arch::Unknown;
    }

    /**
     * @brief Get Platform
     * 
     * Aktif olarak kullanılan platformu döndürür
     *
     * @return Platform
     */
    [[nodiscard]] consteval Platform get_platform() noexcept
{
        if constexpr (os_windows)
            return Platform::MsWin;
        else if constexpr (os_linux)
            return Platform::Linux;
        else if constexpr (os_bsd)
            return Platform::Unix;
        else
            return Platform::Unknown;
    }

    /**
     * @brief Get Os
     * 
     * Aktif olarak kullanılan işletim sistemini döndürür
     *
     * @return Os
     */
    [[nodiscard]] consteval Os get_os() noexcept
    {
        if constexpr (os_windows)
            return Os::Windows;
        else if constexpr (os_linux)
            return Os::Linux;
        else if constexpr (os_bsd)
            return Os::Bsd;
        else
            return Os::Unknown;
    }

    // Current
    export inline constexpr Arch        current_arch    = get_arch();
    export inline constexpr Platform    current_pfm     = get_platform();
    export inline constexpr Os          current_os      = get_os();

    // Preprocessor
    export [[nodiscard]] constexpr std::string_view get_name_arch(const Arch arg_arch = current_arch) noexcept;
    export [[nodiscard]] constexpr std::string_view get_name_platform(const Platform arg_pfm = current_pfm) noexcept;
    export [[nodiscard]] constexpr std::string_view get_name_os(const Os arg_os = current_os) noexcept;
    export [[nodiscard]] std::string get_version() noexcept;

    /**
     * @brief Get Name Arch
     * 
     * İşletim sisteminin mimarisini bulur ve adına göre string döndürür
     *
     * @return string_view 
     */
    [[nodiscard]] constexpr std::string_view get_name_arch(const Arch arg_arch) noexcept
    {
        switch (arg_arch)
        {
            case Arch::Bit32:   return "32-bit";
            case Arch::Bit64:   return "64-bit";
            default:            return "N/A";
        }
    }

    /**
     * @brief Get Name Platform
     *
     * Platformu bulur ve adına göre string döndürür
     * 
     * @return string_view
     */
    [[nodiscard]] constexpr std::string_view get_name_platform(const Platform arg_pfm) noexcept
    {
        switch (arg_pfm)
        {
            case Platform::MsWin:   return "MsWin";
            case Platform::Linux:   return "Unix-Like";
            case Platform::Unix:    return "Unix";
            case Platform::Unknown:
            default:                return "N/A";
        }
    }

    /**
     * @brief Get Name Os
     *
     * İşletim sistemini bulur ve adına göre string döndürür
     * 
     * @return string_view
     */
    [[nodiscard]] constexpr std::string_view get_name_os(const Os arg_os) noexcept
    {
        switch (arg_os)
        {
            case Os::Windows:   return "Windows";
            case Os::Linux:     return "Linux";
            case Os::Bsd:       return "Bsd";
            case Os::Unknown:
                default:        return "N/A";
        }
    }

    /**
     * @brief Get Version
     *
     * Sistemin versiyonunu bulur ve string olarak döndürür
     * 
     * @return string
     */
    [[nodiscard]] std::string get_version() noexcept
    {
        #if defined(__OS_WINDOWS__)
            SYSTEM_INFO tmp_sys_info {};
            ::GetNativeSystemInfo(&tmp_sys_info);

            using RtlGetVersionFn = LONG(WINAPI*)(PRTL_OSVERSIONINFOW);
            if (HMODULE ntdll = ::GetModuleHandleW(L"ntdll.dll"))
            {
                auto tmp_rtl_get_version = reinterpret_cast<RtlGetVersionFn>(::GetProcAddress(ntdll, "RtlGetVersion"));
                if (tmp_rtl_get_version)
                {
                    RTL_OSVERSIONINFOW tmp_os_version_info {};
                    tmp_os_version_info.dwOSVersionInfoSize = sizeof(tmp_os_version_info);

                    if (tmp_rtl_get_version(&tmp_os_version_info) == 0)
                    {
                        return std::format("{}.{}.{}", tmp_os_version_info.dwMajorVersion, tmp_os_version_info.dwMinorVersion, tmp_os_version_info.dwBuildNumber);
                    }
                }
            }
        #elif defined(__OS_LINUX__) || defined(__OS_BSD__)
            struct utsname tmp_uts_name {};
            if (::uname(&tmp_uts_name) == 0)
            {
                return std::string(tmp_uts_name.release);
            }
            
            return "N/A";
        #else
            return "N/A";
        #endif
    }
}