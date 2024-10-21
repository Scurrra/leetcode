#include <vector>
#include <algorithm>

/*
 * @lc app=leetcode id=2239 lang=cpp
 *
 * [2239] Find Closest Number to Zero
 *
 * Time: O(n)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    int findClosestNumber(std::vector<int> &nums)
    {
        short closest = 0;
        for (short i = 1; i < nums.size(); i++)
        {
            if ((std::abs(nums[i]) < std::abs(nums[closest])) || (std::abs(nums[i]) == std::abs(nums[closest]) && nums[i] > nums[closest]))
            {
                closest = i;
            }
        }

        return nums[closest];
    }
};
// @lc code=end
