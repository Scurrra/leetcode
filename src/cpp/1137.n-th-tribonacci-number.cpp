#include <array>

/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int tribonacci(int n)
    {
        std::array<int, 3> trib{{0, 1, 1}};
        if (n < 3)
        {
            return trib[n];
        }

        for (int i = 3; i < n + 1; i++)
        {
            trib = {trib[1], trib[2], trib[0] + trib[1] + trib[2]};
        }

        return trib[2];
    }
};
// @lc code=end
