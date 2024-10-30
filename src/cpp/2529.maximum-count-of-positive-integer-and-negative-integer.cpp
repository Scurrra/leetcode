#include <vector>

/*
 * @lc app=leetcode id=2529 lang=cpp
 *
 * [2529] Maximum Count of Positive Integer and Negative Integer
 * 
 * Time: O(n)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    int maximumCount(std::vector<int> &nums)
    {
        short neg = 0, pos = 0;
        for (auto &&num : nums)
        {
            neg += num < 0;
            pos += num > 0;
        }

        return neg >= pos ? neg : pos;
    }
};
// @lc code=end
