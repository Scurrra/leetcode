#include <string>
#include <stack>

/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 * 
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> validate;
        for (auto &&p : s)
        {
            switch (p)
            {
            case ')':
                if (!validate.empty() && validate.top() == '(')
                    validate.pop();
                else
                    return false;
                break;
            case ']':
                if (!validate.empty() && validate.top() == '[')
                    validate.pop();
                else
                    return false;
                break;
            case '}':
                if (!validate.empty() && validate.top() == '{')
                    validate.pop();
                else
                    return false;
                break;

            default:
                validate.push(p);
                break;
            }
        }

        return validate.size() == 0;
    }
};
// @lc code=end
