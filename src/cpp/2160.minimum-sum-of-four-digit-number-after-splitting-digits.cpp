#include <array>
#include <algorithm>

/*
 * @lc app=leetcode id=2160 lang=cpp
 *
 * [2160] Minimum Sum of Four Digit Number After Splitting Digits
 */

// @lc code=start
class Solution
{
public:
    int minimumSum(int num)
    {
        std::array<char, 4> digits;
        for (int i = 3; i >= 0; i--)
        {
            digits[i] = num % 10;
            num /= 10;
        }

        std::sort(digits.begin(), digits.end());
        int num1 = digits[0] * 10 + digits[2], num2 = digits[1] * 10 + digits[3];
        return num1 + num2;
    }
};
// @lc code=end
