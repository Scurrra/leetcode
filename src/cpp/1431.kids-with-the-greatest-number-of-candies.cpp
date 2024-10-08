#include <vector>
#include <algorithm>

/*
 * @lc app=leetcode id=1431 lang=cpp
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start
class Solution
{
public:
    std::vector<bool> kidsWithCandies(std::vector<int> &candies, int extraCandies)
    {
        int maximum = *std::max_element(candies.begin(), candies.end());
        std::vector<bool> answer(candies.size());
        std::transform(
            candies.begin(),
            candies.end(),
            answer.begin(),
            [&](int &ncandies)
            { return (ncandies + extraCandies) >= maximum; });
        return answer;
    }
};
// @lc code=end
