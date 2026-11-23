// Abdulkadir U. - 2026/11/19

// Module
export module Expect;

// Namespace
export namespace dev::test
{
    /**
    * @brief Expect Equal
    * @tparam L Left Type
    * @tparam R Right Type
    * @return bool True if equal, false otherwise
    */
    template <typename L, typename R>
    inline bool expect_eq
    (
        const L& ar_left,
        const R& ar_right
    )
    {
        return ar_left == ar_right;
    }

    /**
    * @brief Expect Not Equal
    * @tparam L Left Type
    * @tparam R Right Type
    * @return bool True if not equal, false otherwise
    */
    template <typename L, typename R>
    inline bool expect_noteq
    (
        const L& ar_left,
        const R& ar_right
    )
    {
        return ar_left != ar_right;
    }
}