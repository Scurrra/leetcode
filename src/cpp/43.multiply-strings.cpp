#include <string>
#include <vector>
#include <sstream>

/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * Time complexity: O(n m)
 * Space complexity: O(n (n + m))
 */

// @lc code=start
class Solution
{
public:
    std::string multiply(std::string num1, std::string num2)
    {
        if (num1.size() < num2.size())
        {
            std::swap(num1, num2);
        }

        std::vector<std::vector<short>> column;
        for (int i = num2.size() - 1; i >= 0; i--)
        {
            char digit = num2[i] - '0';
            std::vector<short> line(num1.size() + num2.size() + 1, 0);
            for (int j = num1.size() - 1; j >= 0; j--)
            {
                line[i + j + 2] += digit * (num1[j] - '0');
                line[i + j + 1] += line[i + j + 2] / 10;
                line[i + j + 2] %= 10;
            }
            column.push_back(std::move(line));
        }

        for (size_t i = 1; i < column.size(); i++)
        {
            for (int j = column[i].size() - 1; j >= 1; j--)
            {
                column[0][j] += column[i][j];
                column[0][j - 1] += column[0][j] / 10;
                column[0][j] %= 10;
            }
        }

        std::string result = "";
        for (auto &&digit : column[0])
        {
            result += std::to_string(digit);
        }

        while (result.size() > 1 && result[0] == '0')
        {
            result.erase(result.begin());
        }

        return result;
    }
};
// @lc code=end
