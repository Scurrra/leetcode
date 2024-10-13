#include <vector>

/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 *
 * Time: O(n)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> findDuplicates(std::vector<int> &nums)
    {
        std::vector<int> duplicates;
        for (auto &&num : nums)
        {
            auto n = num > 0 ? num : -num;
            if (nums[n - 1] < 0)
            {
                duplicates.emplace_back(n);
            }
            nums[n - 1] = -nums[n - 1];
        }

        return duplicates;
    }
};
// @lc code=end
