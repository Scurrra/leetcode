/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int trailingZeroes(int n)
    {
        if (n == 0)
        {
            return 0;
        }

        int twos = 0, fives = 0, tens = 0;
        for (int i = 1; i <= n; i++)
        {
            auto buf = i;
            while (buf > 0 && buf % 10 == 0)
            {
                tens++;
                buf /= 10;
            }
            while (buf > 0 && buf % 5 == 0)
            {
                fives++;
                buf /= 5;
            }
            while (buf > 0 && buf % 2 == 0)
            {
                twos++;
                buf /= 2;
            }
        }

        return tens + (fives <= twos ? fives : twos);
    }
};
// @lc code=end
