#include <vector>

/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution
{
public:
    int minimumTotal(std::vector<std::vector<int>> &triangle)
    {
        auto dp = triangle.back();

        for (int i = triangle.size() - 2; i >= 0; i--)
        {
            for (size_t j = 0; j < i + 1; j++)
            {
                dp[j] = triangle[i][j] + std::min(dp[j], dp[j + 1]);
            }
        }

        return dp[0];
    }
};
// @lc code=end
