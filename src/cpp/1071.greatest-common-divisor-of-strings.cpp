#include <string>

/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
class Solution
{
public:
    std::string gcdOfStrings(std::string str1, std::string str2)
    {
        if (str1.size() < str2.size())
        {
            std::swap(str1, str2);
        }
        if (!str1.starts_with(str2))
        {
            return "";
        }

        if (str1.size() != str2.size())
        {
            while (!str1.empty() && !str2.empty() && str1 != str2)
            {
                str1.erase(0, str2.size());
                if (str1.size() < str2.size())
                {
                    std::swap(str1, str2);
                }
                if (!str1.starts_with(str2))
                {
                    return "";
                }
            }
            return str1;
        }

        size_t i = 2;
        while (str1.size() % i != 0)
        {
            i++;
        }
        if (i == str1.size())
        {
            return str1;
        }

        std::string gcd, candidate;
        gcd.push_back(str1[0]);
        candidate = str1.substr(i);
        while (str1.find(candidate, i) != std::string::npos)
        {
            gcd = candidate;
            i++;
            while (str1.size() % i != 0)
                i++;

            if (i == str1.size())
            {
                return str1;
            }

            candidate = str1.substr(i);
        }
        
        return gcd;
    }
};
// @lc code=end
