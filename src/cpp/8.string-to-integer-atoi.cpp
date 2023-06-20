#include <string>

/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int myAtoi(std::string s)
    {
        int sign = 0;
        bool is_casting = false;
        bool leading_zeros = false;
        size_t current = 0;
        while (!is_casting)
        {
            switch (s[current])
            {
            case ' ':
                if (leading_zeros) return 0;
                break;
            case '0':
                leading_zeros = true;
                break;
            case '-':
                sign = -1;
                is_casting = true;
                break;
            case '+':
                sign = 1;
                is_casting = true;
                break;
            default:
                is_casting = true;
                current--;
                break;
            }
            current++;
        }

        if (sign != 0)
        {
            if (leading_zeros)
            {
                return 0;
            }
        }
        else
        {
            sign = 1;
        }

        long result = 0;
        int n_digits = 0;
        while (current < s.length() && std::isdigit(s[current]) && n_digits <= 10)
        {
            result = result * 10 + (s[current] - '0');
            current++;
            n_digits += result != 0;
        }

        result *= sign;
        if (result < -2147483648)
        {
            return -2147483648;
        }
        if (result > 2147483647)
        {
            return 2147483647;
        }

        return result;
    }
};
// @lc code=end
