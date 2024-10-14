#include <string>

/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution
{
public:
    std::string rle(std::string &s)
    {
        std::string compressed = "";

        int count = 0;
        char symbol = s[0];
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == symbol)
            {
                count++;
            }
            else
            {
                compressed += std::to_string(count) + symbol;
                count = 1;
                symbol = s[i];
            }
        }

        compressed += std::to_string(count) + symbol;

        return compressed;
    }

    std::string countAndSay(int n)
    {
        std::string s = "1";
        for (size_t i = 0; i < n - 1; i++)
        {
            s = rle(s);
        }
        return s;
    }
};
// @lc code=end
