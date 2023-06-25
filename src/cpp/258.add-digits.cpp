/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 * 
 * Time complexity: O(1)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int addDigits(unsigned int num)
    {
        // while (num >= 10)
        // {
        //     unsigned int sum = 0;
        //     while (num)
        //     {
        //         sum += num % 10;
        //         num /= 10;
        //     }
        //     num = sum;
        // }
        // return num;

        return num == 0 ? 0 : (num - 1) % 9 + 1;
    }
};
// @lc code=end
