#include <vector>

/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 *
 * Time: O(n)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    bool increasingTriplet(std::vector<int> &nums)
    {
        if (nums.size() < 3)
        {
            return false;
        }

        int i = 0x3f3f3f, j = 0x3f3f3f;
        for (size_t k = 0; k < nums.size(); k++)
        {
            if (nums[k] <= i)
            {
                i = nums[k];
            }
            else if (nums[k] <= j)
            {
                j = nums[k];
            }
            else if (i != 0x3f3f3f && j != 0x3f3f3f)
            {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end
