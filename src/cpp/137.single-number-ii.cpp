#include <vector>
#include <map>
#include <algorithm>

/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 * 
 * Time complexity: O(n)
 * Space complexity: O(n/3)
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        std::map<int, bool> is_single;

        for (auto &&num : nums)
        {
            if (is_single.find(num) == is_single.end())
            {
                is_single[num] = true;
            }
            else
            {
                is_single[num] = false;
            }
        }

        return std::find_if(
                   is_single.begin(), is_single.end(),
                   [](const auto &checker)
                   {
                       return checker.second;
                   })
            ->first;
    }
};
// @lc code=end
