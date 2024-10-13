#include <vector>

/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 * 
 * Time: O(n)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> sortArrayByParityII(std::vector<int> &nums)
    {
        std::vector<int> swapped(nums.size());
        size_t odd = 0, even = 0;
        while (nums[odd] % 2 == 0)
        {
            odd++;
        }
        while (nums[even] % 2 == 1)
        {
            even++;
        }

        for (size_t i = 0; i < swapped.size(); i++)
        {
            if (i % 2 == 1)
            {
                swapped[i] = nums[odd++];
                while (odd < nums.size() - 1 && nums[odd] % 2 == 0)
                {
                    odd++;
                }
            }
            else if (i % 2 == 0)
            {
                swapped[i] = nums[even++];
                while (even < nums.size() - 1 && nums[even] % 2 == 1)
                {
                    even++;
                }
            }
        }

        return swapped;
    }
};
// @lc code=end
