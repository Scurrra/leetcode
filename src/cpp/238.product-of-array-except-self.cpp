#include <vector>

/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        std::vector<int> prods(nums.size(), 1);

        int factor = 1;
        for (size_t i = 0; i < nums.size(); i++)
        {
            prods[i] = factor;
            factor *= nums[i];
        }

        factor = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            prods[i] *= factor;
            factor *= nums[i];
        }
        
        return prods;
    }
};
// @lc code=end
