#include <vector>

/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
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
        size_t left = 0, right = nums.size();
        while (left != right && left != right - 1)
        {
            size_t center = left + (right - left) / 2;
            if (target < nums[center])
            {
                right = center;
            }
            else
            {
                left = center;
            }
        }

        if (nums[left] == target)
        {
            return left;
        }
        else
        {
            return -1;
        }
    }
};
// @lc code=end
