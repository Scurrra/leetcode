#include <vector>
#include <functional>

/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution
{
public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums)
    {
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
            dfs(i + 1);
        };

        dfs(0);
        return result;
    }
};
// @lc code=end
