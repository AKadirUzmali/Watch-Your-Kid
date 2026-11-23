// Abdulkadir U. - 2026/11/19
module;

// Include
#include <cstdlib>

// Module
export module Assert;

// Namespace
export namespace dev::test
{
    /**
    * @brief Kill
    * @return void
    */
    inline void kill() noexcept
    {
        std::exit(EXIT_FAILURE);
    }

    /**
    * @brief Assert Equal
    * @tparam L Left Type
    * @tparam R Right Type
    */
    template <typename L, typename R>
    inline void assert_eq
    (
        const L& ar_left,
        const R& ar_right
    )
    {
        if (ar_left == ar_right)
            return;

        kill();
    }

    /**
    * @brief Assert Not Equal
    * @tparam L Left Type
    * @tparam R Right Type
    */
    template <typename L, typename R>
    inline void assert_noteq
    (
        const L& ar_left,
        const R& ar_right
    )
    {
        if (ar_left != ar_right)
            return;

        kill();
    }
}