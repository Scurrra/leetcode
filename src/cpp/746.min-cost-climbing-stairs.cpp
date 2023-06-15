#include <vector>

/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 * 
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution
{
public:
    int minCostClimbingStairs(std::vector<int> &cost)
    {
        if (cost.size() == 2)
        {
            return std::min(cost[0], cost[1]);
        }

        std::vector<int> min_cost(cost.size() - 1);
        min_cost[0] = cost[0];
        min_cost[1] = cost[1];
        for (size_t i = 2; i < cost.size() - 1; i++)
        {
            if (min_cost[i - 2] + cost[i] < min_cost[i - 1] + cost[i])
            {
                min_cost[i] = min_cost[i - 2] + cost[i];
            }
            else
            {
                min_cost[i] = min_cost[i - 1] + cost[i];
            }
        }

        return (min_cost[cost.size() - 3] + cost[cost.size() - 1] < min_cost[cost.size() - 2]) ? 
            min_cost[cost.size() - 3] + cost[cost.size() - 1] 
                : 
            min_cost[cost.size() - 2];
    }
};
// @lc code=end
