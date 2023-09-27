#include <vector>
#include <functional>
#include <algorithm>

/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution
{
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());

        std::vector<std::vector<int>> result;
        std::vector<int> combination;

        std::function<void(size_t, int)> dfs = [&](size_t i, int total)
        {
            if (total == target)
            {
                result.push_back(combination);
                return;
            }

            if (i >= candidates.size() || total > target)
            {
                return;
            }

            int previous = -1;
            for (size_t j = i; j < candidates.size(); j++)
            {
                if (candidates[j] == previous)
                {
                    continue;
                }

                combination.push_back(candidates[j]);
                dfs(j + 1, total + candidates[j]);
                combination.pop_back();
                previous = candidates[j];
            }
        };

        dfs(0, 0);
        return result;
    }
};
// @lc code=end
