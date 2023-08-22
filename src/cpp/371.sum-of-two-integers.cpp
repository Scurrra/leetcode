/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution
{
public:
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            unsigned carry = a & b;
            a ^= b;
            b = carry << 1;
        }

        return a;
    }
};
// @lc code=end
