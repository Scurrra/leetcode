#include <vector>

/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        if (nums.size() == 0)
        {
            return {-1, -1};
        }

        int left = 0, right = nums.size(), middle;
        while (left != right && left != right - 1)
        {
            middle = left + (right - left) / 2;
            if (nums[middle] > target)
            {
                right = middle;
            }
            else if (nums[middle] < target)
            {
                left = middle;
            }
            else
            {
                break;
            }
        }

        if (left == right - 1)
        {
            middle = left;
        }

        if (nums[middle] != target)
        {
            return {-1, -1};
        }

        left = middle;
        while (left > 0 && nums[left - 1] == target)
        {
            left--;
        }

        right = middle;
        while (right < nums.size() - 1 && nums[right + 1] == target)
        {
            right++;
        }

        return {left, right};
    }
};
// @lc code=end
