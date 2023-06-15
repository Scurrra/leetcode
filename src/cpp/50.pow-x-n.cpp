#include <cmath>

/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 * 
 * Time complexity: O(log n)
 * Space complexity: O(log n)
 */

// @lc code=start
class Solution
{
private:
    double binPow(double x, int n)
    {
        if (n == 0)
        {
            return 1.;
        }
        if (n == 1)
        {
            return x;
        }

        double squared = binPow(x * x, n / 2);
        return n % 2 ? squared * x : squared;
    }

public:
    double myPow(double x, int n)
    {
        return n < 0 ? 1 / binPow(x, std::abs(n)) : binPow(x, std::abs(n));
    }
};
// @lc code=end
