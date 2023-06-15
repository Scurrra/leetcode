/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 3)
        {
            return n;
        }

        int n1 = 2, n2 = 3;
        for (int i = 4; i <= n; i++)
        {
            int n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }
        
        return n2;
    }
};
// @lc code=end
