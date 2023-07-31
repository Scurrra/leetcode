#include <vector>

/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int searchInsert(std::vector<int> &nums, int target)
    {
        int left = 0, right = nums.size();
        while (left < right - 1)
        {
            auto middle = (left + right) / 2;
            if (nums[middle] < target)
            {
                left = middle;
            }
            else if (nums[middle] > target)
            {
                right = middle;
            }
            else
            {
                return middle;
            }
        }

        left += nums[left] < target;
        return left;
    }
};
// @lc code=end
