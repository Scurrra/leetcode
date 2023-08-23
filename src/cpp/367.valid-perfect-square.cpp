/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num == 1)
        {
            return true;
        }

        for (long sqrt = 2; sqrt * sqrt <= num; sqrt++)
        {
            if (sqrt * sqrt == num)
            {
                return true;
            }
            
        }
        
        return false;
    }
};
// @lc code=end
