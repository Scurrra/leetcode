#include <vector>
#include <array>
#include <algorithm>

/*
 * @lc app=leetcode id=1937 lang=cpp
 *
 * [1937] Maximum Number of Points with Cost
 * 
 * Time: O(n m)
 * Space: O(m)
 */

// @lc code=start
class Solution
{
public:
    long long maxPoints(std::vector<std::vector<int>> &points)
    {
        auto n = points.size(), m = points[0].size();
        std::array<std::vector<long long>, 2> dp{std::vector<long long>(m), std::vector<long long>(m)};
        std::array<std::vector<long long>, 2> curmax{std::vector<long long>(m), std::vector<long long>(m)};
        for (size_t i = 0; i < m; i++)
        {
            dp[0][i] = points[0][i];
        }
        
        for (size_t i = 1; i < n; i++)
        {
            curmax[0][0] = dp[0][0];
            for (size_t j = 1; j < m; j++)
            {
                curmax[0][j] = std::max(curmax[0][j - 1] - 1, dp[0][j]);
            }
            
            curmax[1][m - 1] = dp[0][m - 1];
            for (int j = m - 2; j >= 0; j--)
            {
                curmax[1][j] = std::max(curmax[1][j + 1] - 1, dp[0][j]);
            }
            
            for (size_t j = 0; j < m; j++)
            {
                dp[1][j] = std::max(curmax[0][j], curmax[1][j]) + points[i][j];
            }
            
            std::swap(dp[0], dp[1]);
        }

        return *std::max_element(dp[0].begin(), dp[0].end());
    }
};
// @lc code=end
