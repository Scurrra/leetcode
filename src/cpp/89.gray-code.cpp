#include <vector>
#include <numeric>
#include <algorithm>

/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> grayCode(int n)
    {
        std::vector<int> result(1 << n);
        std::iota(result.begin(), result.end(), 0);
        std::transform(
            result.begin(), result.end(), result.begin(),
            [](int &n)
            { return n ^ (n >> 1); });

        return result;
    }
};
// @lc code=end
