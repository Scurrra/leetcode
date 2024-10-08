#include <array>

/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        std::array<int, 2> fib{{0, 1}};
        if (n < 2)
        {
            return fib[n];
        }

        for (int i = 2; i < n + 1; i++)
        {
            fib = {fib[1], fib[0] + fib[1]};
        }

        return fib[1];
    }
};
// @lc code=end

