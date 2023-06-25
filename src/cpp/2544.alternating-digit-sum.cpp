#include <vector>

/*
 * @lc app=leetcode id=2544 lang=cpp
 *
 * [2544] Alternating Digit Sum
 *
 * Time complexity: O(log n)
 * Space complexity: O(log n)
 */

// @lc code=start
class Solution
{
public:
    int alternateDigitSum(int n)
    {
        std::vector<char> digits;
        while (n)
        {
            digits.push_back(n % 10);
            n /= 10;
        }

        int sum = 0;
        bool odd_length = digits.size() % 2;
        for (size_t i = 0; i < digits.size(); i++)
        {
            sum += (odd_length ? 1 : -1) * (i % 2 ? -1 : 1) * digits[i];
        }

        return sum;
    }
};
// @lc code=end
