#include <vector>

/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 * 
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        size_t l = 0, r = nums.size() - 1;

        while (l <= r)
        {
            auto m = l + (r - l) / 2;
            if (nums[m] == target)
            {
                return m;
            }

            // left sorted part
            if (nums[l] <= nums[m])
            {
                if (target > nums[m] || target < nums[l])
                {
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
            else
            {
                if (target < nums[m] || target > nums[r])
                {
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
        }

        return -1;
    }
};
// @lc code=end
