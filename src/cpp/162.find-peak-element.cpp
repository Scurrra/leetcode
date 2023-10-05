#include <vector>

/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 *
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int findPeakElement(std::vector<int> &nums)
    {
        size_t l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            auto m = l + (r - l) / 2;

            if (m > 0 && nums[m] < nums[m - 1])
            {
                r = m - 1;
            }
            else if (m < nums.size() - 1 && nums[m] < nums[m + 1])
            {
                l = m + 1;
            }
            else
            {
                return m;
            }
        }

        return -1;
    }
};
// @lc code=end
