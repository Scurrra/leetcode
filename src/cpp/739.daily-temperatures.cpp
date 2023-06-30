#include <vector>

/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 * 
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures)
    {
        std::vector<int> result(temperatures.size(), 0);
        std::vector<std::pair<int, int>> stack;

        for (size_t i = 0; i < temperatures.size(); i++)
        {
            while (!stack.empty() && temperatures[i] > stack[stack.size() - 1].first)
            {
                auto &[temp, ind] = stack[stack.size() - 1];
                stack.pop_back();
                result[ind] = i - ind;
            }
            stack.emplace_back(std::make_pair(temperatures[i], i));
        }

        return result;
    }
};
// @lc code=end
