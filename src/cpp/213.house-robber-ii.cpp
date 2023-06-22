#include <vector>

/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int rob(std::vector<int> &nums)
    {
        int rob1 = 0, rob2 = 0;
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            int temp = std::max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        int first = rob2;

        rob1 = 0, rob2 = 0;
        for (size_t i = 1; i < nums.size(); i++)
        {
            int temp = std::max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        int rest = rob2;

        return std::max(nums[0], std::max(first, rest));
    }
};
// @lc code=end
