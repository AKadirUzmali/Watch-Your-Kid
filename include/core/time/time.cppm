// Abdulkadir U. - 2026/11/24
module;

// Include
#include <string_view>
#include <sstream>
#include <iomanip>
#include <chrono>

// Module
export module core.time;

// Import
import core.sys.hardware.os;

// Using Namespace
using namespace core::sys::hardware;

// Namespace
namespace core::time
{
    // Preprocessor
    export [[maybe_unused]] [[nodiscard]] std::string_view get_date();
    export [[maybe_unused]] [[nodiscard]] std::string_view get_time();
    export [[maybe_unused]] [[nodiscard]] std::string_view get_timestamp();

    /**
     * @brief Get Date
     *
     * Yıl/Ay/Gün bilgilerini alsın ve metin olarak döndürsün
     * 
     * @return string_view 
     */
    [[maybe_unused]] [[nodiscard]] std::string_view get_date()
    {
        const auto tmp_now = std::chrono::system_clock::now();
        const auto tmp_time = std::chrono::system_clock::to_time_t(tmp_now);

        std::tm tmp_tm {};

        #if defined(__OS_WINDOWS__)
            localtime_s(&tmp_tm, &tmp_time);
        #elif defined(__OS_LINUX__) || defined(__OS_BSD__)
            localtime_r(&tmp_time, &tmp_tm);
        #else
            tmp_tm = *std::localtime(&tmp_time);
        #endif

        constexpr size_t tmp_buff_size = 16;
        static thread_local char tmp_buffer[tmp_buff_size]; // YYYY-MM-DD + '\0'
        std::strftime(tmp_buffer, sizeof(tmp_buffer), "%Y-%m-%d", &tmp_tm);

        return std::string_view {tmp_buffer};
    }

    /**
     * @brief Get Time
     * 
     * Saat/Dakika/Saniye bilgilerini alsın ve metin olarak döndürsün
     *
     * @return string_view 
     */
    [[maybe_unused]] [[nodiscard]] std::string_view get_time()
    {
        auto tmp_now = std::chrono::system_clock::now();
        auto tmp_time = std::chrono::system_clock::to_time_t(tmp_now);
        auto tmp_ms = std::chrono::duration_cast<std::chrono::milliseconds>(tmp_now.time_since_epoch()) % 1000;

        std::tm tmp_tm {};

        #if defined(__OS_WINDOWS__)
            localtime_s(&tmp_tm, &tmp_time);
        #elif defined(__OS_LINUX__) || defined(__OS_BSD__)
            localtime_r(&tmp_time, &tmp_tm);
        #else
            tmp_tm = *std::localtime(&tmp_time);
        #endif

        constexpr size_t tmp_buff_size = 32;
        static thread_local char tmp_buffer[tmp_buff_size]; // HH:MM:SS:MMM + '\0'

        std::snprintf(tmp_buffer, sizeof(tmp_buffer), "%02d:%02d:%02d:%03lld", tmp_tm.tm_hour, tmp_tm.tm_min, tmp_tm.tm_sec, static_cast<long long>(tmp_ms.count()));
        return std::string_view {tmp_buffer};
    }

    /**
     * @brief Get Timestamp
     *
     * Yıl/Ay/Gün ve Saat/Dakika/Saniye bilgilerini birlikte düzenli bir metin olarak döndürsün
     *
     * @return string_view 
     */
    [[maybe_unused]] [[nodiscard]] std::string_view get_timestamp()
    {
        auto tmp_now = std::chrono::system_clock::now();
        auto tmp_time = std::chrono::system_clock::to_time_t(tmp_now);
        auto tmp_ms = std::chrono::duration_cast<std::chrono::milliseconds>(tmp_now.time_since_epoch()) % 1000;

        std::tm tmp_tm {};

        #if defined(__OS_WINDOWS__)
            localtime_s(&tmp_tm, &tmp_time);
        #elif defined(__OS_LINUX__) || defined(__OS_BSD__)
            localtime_r(&tmp_time, &tmp_tm);
        #else
            tmp_tm = *std::localtime(&tmp_time);
        #endif

        constexpr size_t tmp_time_buffer_size = 64;
        static thread_local char tmp_buffer[tmp_time_buffer_size]; // YYYY-MM-DD + HH:MM:SS:MMM + '\0'

        std::snprintf(
            tmp_buffer, sizeof(tmp_buffer),
            "%04d-%02d-%02d %02d:%02d:%02d:%03lld",
            tmp_tm.tm_year + 1900,
            tmp_tm.tm_mon + 1,
            tmp_tm.tm_mday,
            tmp_tm.tm_hour,
            tmp_tm.tm_min,
            tmp_tm.tm_sec,
            static_cast<long long>(tmp_ms.count())
        );

        return std::string_view {tmp_buffer};
    }
}