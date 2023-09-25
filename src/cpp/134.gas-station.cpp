#include <vector>
#include <numeric>

/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost)
    {
        if (
            std::accumulate(gas.begin(), gas.end(), 0) <
            std::accumulate(cost.begin(), cost.end(), 0))
        {
            return -1;
        }

        int total = 0, result = 0;
        for (size_t i = 0; i < gas.size(); i++)
        {
            total += (gas[i] - cost[i]);
            if (total < 0)
            {
                total = 0;
                result = i + 1;
            }
        }

        return result;
    }
};
// @lc code=end
