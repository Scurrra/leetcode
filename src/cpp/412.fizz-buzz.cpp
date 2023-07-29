#include <vector>
#include <string>

/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
class Solution
{
public:
    std::vector<std::string> fizzBuzz(int n)
    {
        std::vector<std::string> result(n);
        for (int i = 1; i <= n; i++)
        {
            if (i % 15 == 0)
            {
                result[i - 1] = "FizzBuzz";
            }
            else if (i % 5 == 0)
            {
                result[i - 1] = "Buzz";
            }
            else if (i % 3 == 0)
            {
                result[i - 1] = "Fizz";
            }
            else
            {
                result[i - 1] = std::to_string(i);
            }
        }

        return result;
    }
};
// @lc code=end
