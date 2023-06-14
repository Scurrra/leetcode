#include <vector>
#include <map>
#include <algorithm>

/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 * 
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> singleNumber(std::vector<int> &nums)
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

        std::vector<int> singles;
        for (auto &&checker : is_single)
        {
            if (checker.second)
            {
                singles.push_back(std::move(checker.first));
            }
        }
        return singles;
    }
};
// @lc code=end
