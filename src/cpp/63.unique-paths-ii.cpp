#include <vector>

/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution
{
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid)
    {
        std::vector<std::vector<int>> dp(obstacleGrid.size(), std::vector<int>(obstacleGrid[0].size()));
        for (size_t i = 0; i < dp.size(); i++)
        {
            if (obstacleGrid[i][0] == 1)
            {
                break;
            }

            dp[i][0] = 1;
        }
        for (size_t j = 0; j < dp[0].size(); j++)
        {
            if (obstacleGrid[0][j] == 1)
            {
                break;
            }

            dp[0][j] = 1;
        }

        for (size_t i = 1; i < dp.size(); i++)
        {
            for (size_t j = 1; j < dp[0].size(); j++)
            {
                dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[dp.size() - 1].back();
    }
};
// @lc code=end
