#include <vector>

/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        // dp but in O(1) memory
        int max = -0x3f3f, sum = 0;
        for (auto &&num : nums)
        {
            sum = std::max(num, sum + num);
            max = std::max(sum, max);
        }
        
        return max;
    }
};
// @lc code=end
