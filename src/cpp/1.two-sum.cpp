#include <vector>
#include <map>

/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 * 
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::map<int, int> seen;

        for (int i = 0; i < nums.size(); i++)
        {
            if (auto j = seen.find(target - nums[i]); j != seen.end())
            {
                std::vector<int> ans = {i, j->second};
                return ans;
            }

            seen.insert({nums[i], i});
        }

        return std::vector<int>();
    }
};
// @lc code=end
