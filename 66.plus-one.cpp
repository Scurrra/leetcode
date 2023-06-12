#include <vector>

/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> plusOne(std::vector<int> &digits)
    {
        size_t last_increased = digits.size() - 1;
        digits[last_increased] += 1;

        while (last_increased > 0 && digits[last_increased] > 9)
        {
            digits[last_increased--] = 0;
            digits[last_increased] += 1;
        }

        if (last_increased == 0)
        {
            if (digits[0] == 10)
            {
                digits[0] = 0;
                digits.insert(digits.begin(), 1);
            }
        }

        return digits;
    }
};
// @lc code=end
