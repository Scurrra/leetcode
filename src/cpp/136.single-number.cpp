#include <vector>
#include <numeric>

/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        return std::accumulate(
            nums.begin(), nums.end(),
            0, [](int acc, int next)
            { return acc ^ next; });
    }
};
// @lc code=end
