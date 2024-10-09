#include <vector>

/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution
{
public:
    int minPathSum(std::vector<std::vector<int>> &grid)
    {
        std::vector<std::vector<int>> dp(grid.size(), std::vector<int>(grid[0].size()));
        dp[0][0] = grid[0][0];
        for (size_t i = 1; i < dp.size(); i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (size_t j = 1; j < dp[0].size(); j++)
        {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (size_t i = 1; i < dp.size(); i++)
        {
            for (size_t j = 1; j < dp[i].size(); j++)
            {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp.back().back();
    }
};
// @lc code=end
