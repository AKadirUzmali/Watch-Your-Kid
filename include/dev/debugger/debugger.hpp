// Abdulkadir U. - 2026/11/27
#pragma once

// Include
#if defined (__DEBUGGER_T_DEV__)
    #include <cstdint>
    #include <set>
#endif

// Debugger Not Defined
#if !defined (__DEBUGGER_T_DEV__)
    #define DEBUGGER(code, function)
    #define DEBUGGER_ADD_CODE(code)
    #define DEBUGGER_DEL_CODE(code)
#else
    // Namespace
    namespace dev::debugger
    {
        inline std::set<std::uint32_t> debug_codes;
    }

    #define DEBUGGER(code, function) \
        do \
        { \
            const auto tmp_target_code = static_cast<std::uint32_t>(code); \
            if (dev::debugger::debug_codes.contains(tmp_target_code)) \
            { \
                function; \
            } \
        } while (0)

    #define DEBUGGER_ADD_CODE(code) \
        do \
        { \
            dev::debugger::debug_codes.insert(static_cast<std::uint32_t>(code)); \
        } while (0)

    #define DEBUGGER_DEL_CODE(code) \
        do \
        { \
            dev::debugger::debug_codes.erase(static_cast<std::uint32_t>(code)); \
        } while (0)
#endif