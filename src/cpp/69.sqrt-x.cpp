/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 * 
 * Time complexity: O(sqrt sqrt x)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
        {
            return 0;
        }
           
        // Newton's algorithm
        long n = 1;
        bool decreased = false;

        while (true)
        {
            long nn = (n + x / n) >> 1;
            if (n == nn || nn > n && decreased)
            {
                break;
            }
            decreased = nn < n;
            n = nn;
        }
        
        return n;
    }
};
// @lc code=end
