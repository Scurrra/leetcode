#include <string>
#include <vector>

/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution
{
public:
    std::string removeKdigits(std::string num, int k)
    {
        std::vector<char> answer{num[0]};
        answer.reserve(num.size() - k);
        for (size_t i = 1; i < num.size(); i++)
        {
            while (k && !answer.empty() && answer.back() > num[i])
            {
                answer.pop_back();
                k--;
            }

            answer.push_back(num[i]);
        }

        if (answer.size() == k)
        {
            return "0";
        }

        if (k != 0)
        {
            int i = 0;
            while (answer[i] == '0' && k < answer.size() - 1 - i)
                i++;
            return std::string(answer.begin() + i, answer.end() - k);
        }

        while (answer[k] == '0' && k < answer.size() - 1)
            k++;
        return std::string(answer.begin() + k, answer.end());
    }
};
// @lc code=end
