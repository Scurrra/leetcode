#include <string>

/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 * 
 * Time complexity: O(n)
 * Space complexity: O(1) --- modifying `a` inplace
 */

// @lc code=start
class Solution
{
public:
    std::string addBinary(std::string a, std::string b)
    {
        if (b.size() > a.size())
        {
            std::swap(a, b);
        }

        bool shift = false;
        size_t i;
        for (i = 1; i <= b.size(); i++)
        {
            char a_last = a[a.size() - i] - '0', b_last = b[b.size() - i] - '0';
            a[a.size() - i] = (a_last ^ b_last ^ shift) + '0';
            shift = (a_last & b_last) | (a_last & shift) | (b_last & shift);
        }
        while (i <= a.size())
        {
            auto a_last = (a[a.size() - i] - '0');
            a[a.size() - i] = (a_last ^ shift) + '0';
            shift &= a_last;
            i++;
        }
        if (shift)
        {
            a = "1" + a;
        }

        return a;
    }
};
// @lc code=end
