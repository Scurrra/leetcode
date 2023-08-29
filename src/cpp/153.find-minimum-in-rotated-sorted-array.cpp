#include <vector>

/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 * 
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int findMin(std::vector<int> &nums)
    {
        size_t l = 0, r = nums.size() - 1;

        while (l < r)
        {
            auto m = l + (r - l) / 2;
            if (nums[m] > nums[r])
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }

        return nums[l];
    }
};
// @lc code=end
