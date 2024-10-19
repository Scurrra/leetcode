#include <vector>

/*
 * @lc app=leetcode id=1913 lang=cpp
 *
 * [1913] Maximum Product Difference Between Two Pairs
 * 
 * Time: O(n)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    int maxProductDifference(std::vector<int> &nums)
    {
        short maxi1 = 0, maxi2 = 0, mini1 = 0, mini2 = 0;
        for (short i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= nums[maxi1])
            {
                maxi1 = i;
            }

            if (nums[i] <= nums[mini1])
            {
                mini1 = i;
            }
        }

        if (maxi1 == 0)
            maxi2++;

        if (mini1 == 0)
            mini2++;

        for (short i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= nums[maxi2] && i != maxi1)
            {
                maxi2 = i;
            }

            if (nums[i] <= nums[mini2] && i != mini1)
            {
                mini2 = i;
            }
        }

        return nums[maxi1] * nums[maxi2] - nums[mini1] * nums[mini2];
    }
};
// @lc code=end
