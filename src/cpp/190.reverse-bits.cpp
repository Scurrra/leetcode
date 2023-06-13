#include <cstdint>

/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 * 
 * Time complexity: O(log(n))
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t reverse = 0;
        uint32_t rev_i = 31;
        while (n > 0)
        {
            if (n % 2)
            {
                reverse = reverse | (1 << rev_i);
            }
            n /= 2;
            rev_i--;
        }

        return reverse;
    }
};
// @lc code=end
