#include <vector>

/*
 * @lc app=leetcode id=2293 lang=cpp
 *
 * [2293] Min Max Game
 * 
 * Time complexity: O(n log n)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution
{
public:
    int minMaxGame(std::vector<int> &nums)
    {
        while (nums.size() != 1)
        {
            std::vector<int> new_nums(nums.size() / 2);
            for (size_t i = 0; i < new_nums.size(); i++)
            {
                new_nums[i] = i % 2 ? std::max(nums[2 * i], nums[2 * i + 1]) : std::min(nums[2 * i], nums[2 * i + 1]);
            }
            nums = new_nums;
        }

        return nums[0];
    }
};
// @lc code=end
