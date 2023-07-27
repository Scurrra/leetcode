/*
 * @lc app=leetcode id=507 lang=cpp
 *
 * [507] Perfect Number
 * 
 * Time complexity: O(sqrt n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        if (num == 1)
        {
            return false;
        }
        
        int magic = 1;
        for (int i = 2; i * i < num; i++)
        {
            if (num % i == 0)
            {
                magic += i;
                magic += num / i;
            }

            if (magic > num)
            {
                return false;
            }
        }

        return magic == num;
    }
};
// @lc code=end
