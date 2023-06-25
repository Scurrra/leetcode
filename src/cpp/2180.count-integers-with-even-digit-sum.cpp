/*
 * @lc app=leetcode id=2180 lang=cpp
 *
 * [2180] Count Integers With Even Digit Sum
 * 
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int countEven(int num)
    {
        int sum = 0, n = num;
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }

        return sum % 2 ? (num-1) / 2 : num / 2;
    }
};
// @lc code=end
