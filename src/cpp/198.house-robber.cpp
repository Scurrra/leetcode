#include <vector>

/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
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
        for (auto &&n : nums)
        {
            int temp = std::max(n+rob1, rob2);
            rob1 = rob2;
            rob2=temp;
        }

        return rob2;
    }
};
// @lc code=end
