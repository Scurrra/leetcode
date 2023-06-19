#include <vector>
#include <string>
#include <stack>

/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution
{
public:
    int evalRPN(std::vector<std::string> &tokens)
    {
        std::stack<int> nums;
        for (auto &&token : tokens)
        {
            if (token == "+")
            {
                int num_a = nums.top();
                nums.pop();
                int num_b = nums.top();
                nums.pop();
                nums.push(num_b + num_a);
            }
            else if (token == "-")
            {
                int num_a = nums.top();
                nums.pop();
                int num_b = nums.top();
                nums.pop();
                nums.push(num_b - num_a);
            }
            else if (token == "*")
            {
                int num_a = nums.top();
                nums.pop();
                int num_b = nums.top();
                nums.pop();
                nums.push(num_b * num_a);
            }
            else if (token == "/")
            {
                int num_a = nums.top();
                nums.pop();
                int num_b = nums.top();
                nums.pop();
                nums.push(num_b / num_a);
            }
            else
            {
                nums.push(std::stoi(token));
            }
        }
        return nums.top();
    }
};
// @lc code=end
