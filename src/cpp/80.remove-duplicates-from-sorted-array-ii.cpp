#include <vector>

/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        size_t l = 0, r = 0;
        while (r < nums.size())
        {
            auto count = 1;
            while (r + 1 < nums.size() && nums[r] == nums[r + 1])
            {
                r++;
                count++;
            }

            nums[l++] = nums[r];
            if (count > 1)
            {
                nums[l++] = nums[r];
            }
            r++;
        }

        return l;
    }
};
// @lc code=end
