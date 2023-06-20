#include <vector>

/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * Time complexity: O(log n)
 * Space complexity: O(log n)
 */

// @lc code=start
class Solution
{
public:
    std::vector<char> split(int n)
    {
        std::vector<char> digits;
        while (n)
        {
            digits.push_back(n % 10);
            n /= 10;
        }
        return digits;
    }

    int reverse(int x)
    {
        if (x == -2147483648)
        {
            return 0;
        }

        const std::vector<char> int_max = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};

        int sign = x < 0 ? -1 : 1;
        x *= sign;

        auto x_digits = split(x);
        if (x_digits.size() >= 10 && x_digits > int_max)
        {
            return 0;
        }

        x = 0;
        for (auto &&digit : x_digits)
        {
            x = x * 10 + digit;
        }
        return sign * x;
    }
};
// @lc code=end
