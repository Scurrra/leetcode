#include <vector>

/*
 * @lc app=leetcode id=1464 lang=cpp
 *
 * [1464] Maximum Product of Two Elements in an Array
 * 
 * Time: O(n)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(std::vector<int> &nums)
    {
        int min1 = 0, min2 = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] > min1)
            {
                min2 = min1;
                min1 = nums[i];
            }
            else if (nums[i] > min2)
            {
                min2 = nums[i];
            }
        }

        return (min1 - 1) * (min2 - 1);
    }
};
// @lc code=end
