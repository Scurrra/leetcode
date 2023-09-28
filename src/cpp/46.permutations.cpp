#include <vector>
#include <deque>
#include <functional>

/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution
{
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return {nums};
        }

        std::function<std::vector<std::vector<int>>(std::deque<int>&)> gen = [&](std::deque<int> &nums)
        {
            if (nums.size() == 1)
            {
                return std::vector<std::vector<int>>{{nums[0]}};
            }

            std::vector<std::vector<int>> result;
            for (size_t i = 0; i < nums.size(); i++)
            {
                auto num = nums.front();
                nums.pop_front();
                auto perms = gen(nums);

                for (auto &&perm : perms)
                {
                    perm.push_back(num);
                }
                result.insert(result.end(), perms.begin(), perms.end());
                nums.push_back(num);
            }
            return result;
        };

        std::deque<int> _nums(nums.begin(), nums.end());
        return gen(_nums);
    }
};
// @lc code=end
