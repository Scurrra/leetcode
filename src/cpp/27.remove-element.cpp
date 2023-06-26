#include <vector>

/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        int k = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[k++] = nums[i];
            }
        }

        return k;
    }
};
// @lc code=end
