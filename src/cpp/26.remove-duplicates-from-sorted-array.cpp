#include <vector>

/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        size_t l = 1;
        for (size_t r = 1; r < nums.size(); r++)
        {
            if (nums[r] != nums[r - 1])
            {
                nums[l++] = nums[r];
            }
        }

        return l;
    }
};
// @lc code=end
