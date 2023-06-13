#include <cstdint>

/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 * 
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        uint8_t ones = 0;
        while (n > 0)
        {
            ones += n % 2;
            n /= 2;
        }
        
        return ones;
    }
};
// @lc code=end
