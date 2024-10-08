#include <vector>
#include <numeric>
#include <array>
#include <iostream>

/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        std::array<std::vector<int>, 2> dp{std::vector<int>(n, 1), std::vector<int>(n, 1)};

        for (size_t i = 1; i < m; i++)
        {
            for (size_t j = 1; j < n; j++)
            {
                dp[1][j] = dp[0][j] + dp[1][j - 1];
            }

            std::swap(dp[1], dp[0]);
        }

        return dp[0][n - 1];
    }
};
// @lc code=end
