#include <vector>
#include <functional>

/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution
{
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target)
    {
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

            combination.push_back(candidates[i]);
            dfs(i, total + candidates[i]);

            combination.pop_back();
            dfs(i + 1, total);
        };

        dfs(0, 0);
        return result;
    }
};
// @lc code=end
