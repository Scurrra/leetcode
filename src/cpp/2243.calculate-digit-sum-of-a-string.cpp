#include <string>

/*
 * @lc app=leetcode id=2243 lang=cpp
 *
 * [2243] Calculate Digit Sum of a String
 *
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution
{
private:
    std::string substr_sum(std::string sub_s)
    {
        int sum = 0;
        for (auto &&c : sub_s)
        {
            sum += c - '0';
        }

        return std::to_string(sum);
    }

public:
    std::string digitSum(std::string s, int k)
    {
        while (s.size() > k)
        {
            int substr_n = s.size() / k;
            std::string new_s = "";

            for (size_t i = 0; i < substr_n; i++)
            {
                new_s += substr_sum(s.substr(i * k, k));
            }
            if (s.size() % k != 0)
            {
                new_s += substr_sum(s.substr(substr_n * k, s.size() - substr_n * k));
            }
            s = std::move(new_s);
        }

        return s;
    }
};
// @lc code=end
