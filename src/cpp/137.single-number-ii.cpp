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
        std::map<int, bool> is_triple;

        for (auto &&num : nums)
        {
            if (is_triple.find(num) == is_triple.end())
            {
                is_triple[num] = true;
            }
            else
            {
                is_triple[num] = false;
            }
        }

        return std::find_if(
                   is_triple.begin(), is_triple.end(),
                   [](const auto &checker)
                   {
                       return checker.second;
                   })
            ->first;
    }
};
// @lc code=end
