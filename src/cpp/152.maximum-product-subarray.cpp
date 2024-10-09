#include <vector>

/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(std::vector<int> &nums)
    {
        // dp but in O(1) memory
        int max = -0x3f3f, nprod = 1, pprod = 1;
        for (auto &&num : nums)
        {
            auto curmax = pprod * num;
            pprod = std::max(std::max(curmax, num*nprod), num);
            nprod = std::min(std::min(curmax, num*nprod), num);
            max = std::max(max, pprod);
        }
        
        return max;
    }
};
// @lc code=end
