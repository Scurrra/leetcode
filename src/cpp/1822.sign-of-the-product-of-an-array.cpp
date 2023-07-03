#include <vector>
#include <algorithm>
#include <numeric>

/*
 * @lc app=leetcode id=1822 lang=cpp
 *
 * [1822] Sign of the Product of an Array
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int arraySign(std::vector<int> &nums)
    {
        std::transform(
            nums.begin(), nums.end(),
            nums.begin(), [](int num)
            { return num == 0 ? 0 : num > 0 ? 1
                                            : -1; });
        return std::accumulate(
            nums.begin(), nums.end(), 1,
            std::multiplies<>{});
    }
};
// @lc code=end
