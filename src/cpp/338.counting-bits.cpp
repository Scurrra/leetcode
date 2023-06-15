#include <vector>

/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 * 
 * Time complexity: O(n)
 * Space complexity: O(1), because resulting vector is not counted
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> countBits(int n)
    {
        std::vector<int> bits(n + 1);
        for (size_t i = 1; i < n + 1; i++)
        {
            bits[i] = bits[i / 2] + i % 2;
        }

        return bits;
    }
};
// @lc code=end
