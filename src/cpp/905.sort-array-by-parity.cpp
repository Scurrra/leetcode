#include <vector>

/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 * 
 * Time: O(n)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> sortArrayByParity(std::vector<int> nums)
    {
        int l = 0, r = nums.size() - 1;
        while (l < r && l < nums.size() && r >= 0)
        {
            while (l < nums.size() && nums[l] % 2 == 0)
            {
                l++;
            }
            while (r >= 0 && nums[r] % 2 == 1)
            {
                r--;
            }

            if (l < r)
            {
                std::swap(nums[l], nums[r]);
                l++;
                r--;
            }
        }

        return nums;
    }
};
// @lc code=end
