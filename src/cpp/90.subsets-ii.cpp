#include <vector>
#include <functional>
#include <algorithm>

/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution
{
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> result;
        std::vector<int> subset;

        std::function<void(size_t)> dfs = [&](size_t i)
        {
            if (i >= nums.size())
            {
                result.push_back(subset);
                return;
            }

            subset.push_back(nums[i]);
            dfs(i + 1);
            subset.pop_back();

            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            {
                i++;
            }
            dfs(i + 1);
        };

        dfs(0);
        return result;
    }
};
// @lc code=end
