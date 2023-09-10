#include <vector>
#include <string>
#include <functional>

/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution
{
public:
    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::string> result;
        std::vector<char> stack;

        std::function<void(int, int)> backtrack = [&](int open, int closed)
        {
            if (open == closed && open == n)
            {
                result.emplace_back(
                    std::string(stack.begin(), stack.end()));
            }

            if (open < n)
            {
                stack.push_back('(');
                backtrack(open + 1, closed);
                stack.pop_back();
            }

            if (closed < open)
            {
                stack.push_back(')');
                backtrack(open, closed + 1);
                stack.pop_back();
            }
        };

        backtrack(0, 0);

        return result;
    }
};
// @lc code=end
