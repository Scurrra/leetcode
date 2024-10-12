#include <vector>

/*
 * @lc app=leetcode id=2177 lang=cpp
 *
 * [2177] Find Three Consecutive Integers That Sum to a Given Number
 * 
 * Time: O(1)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    std::vector<long long> sumOfThree(long long num)
    {
        if (num % 3 == 0)
        {
            auto mid = num / 3;
            return {mid - 1, mid, mid + 1};
        }
        
        return {};
    }
};
// @lc code=end
