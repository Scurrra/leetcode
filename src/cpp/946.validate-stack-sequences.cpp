#include <vector>
#include <stack>

/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 * 
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution
{
public:
    bool validateStackSequences(std::vector<int> &pushed, std::vector<int> &popped)
    {
        std::stack<int> stack;
        size_t popping = 0;
        for (auto &&pushing : pushed)
        {
            if (pushing == popped[popping])
            {
                popping++;

                if (!stack.empty() && popping < popped.size())
                {
                    while (!stack.empty() && popping < popped.size() && stack.top() == popped[popping])
                    {
                        stack.pop();
                        popping++;
                    }
                }

                continue;
            }

            stack.push(pushing);
        }

        if (!stack.empty() && popping < popped.size())
        {
            while (!stack.empty() && popping < popped.size() && stack.top() == popped[popping])
            {
                stack.pop();
                popping++;
            }
        }

        return stack.empty() && popping == popped.size();
    }
};
// @lc code=end
