#include <string>

/*
 * @lc app=leetcode id=1945 lang=cpp
 *
 * [1945] Sum of Digits of String After Convert
 * 
 * Time complexity: O(2 log n + (k - 1) * log sum) = O(k log n)
 * Space complexity: O(log n)
 */

// @lc code=start
class Solution
{
public:
    int getLucky(std::string s, int k)
    {
        std::string num_str = "";
        for (auto &&c : s)
        {
            num_str += std::to_string(c - 'a' + 1);
        }

        int sum = 0;
        for (auto &&c : num_str)
        {
            sum += c - '0';
        }

        int num = sum;
        for (size_t i = 1; i < k; i++)
        {
            sum = 0;
            while (num)
            {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }

        return num;
    }
};
// @lc code=end
