#include <vector>
#include <algorithm>

/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(std::vector<int> &prices)
    {
        int max_profit = 0;
        int lowest_price = prices[0];
        for (size_t i = 1; i < prices.size(); i++)
        {
            lowest_price = std::min(prices[i], lowest_price);
            max_profit = std::max(max_profit, prices[i] - lowest_price);
        }
        
        return max_profit;
    }
};
// @lc code=end
