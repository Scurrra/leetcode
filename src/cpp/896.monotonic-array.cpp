#include <vector>

/*
 * @lc app=leetcode id=896 lang=cpp
 *
 * [896] Monotonic Array
 * 
 * Time: O(n)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    bool isMonotonic(std::vector<int> &nums)
    {
        bool isDescending = true, isAscending = true;
        for (size_t i = 1; i < nums.size() && (isAscending || isDescending); i++)
        {
            if (isDescending && nums[i] > nums[i - 1])
            {
                isDescending = false;
            }

            if (isAscending && nums[i] < nums[i - 1])
            {
                isAscending = false;
            }
        }

        return isAscending || isDescending;
    }
};
// @lc code=end
