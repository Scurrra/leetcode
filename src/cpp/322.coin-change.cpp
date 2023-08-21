#include <vector>

/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 * 
 * Time complexity: O(n * amount)
 * Space complexity: O(amount)
 */

// @lc code=start
class Solution
{
public:
    int coinChange(std::vector<int> &coins, int amount)
    {
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i < amount + 1; i++)
        {
            for (auto &&coin : coins)
            {
                if (i - coin >= 0)
                {
                    dp[i] = std::min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        return dp[amount] != amount + 1 ? dp[amount] : -1;
    }
};
// @lc code=end
