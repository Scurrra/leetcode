#include <vector>
#include <algorithm>

/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */

// @lc code=start
class Solution
{
private:
    std::vector<int> split(int n)
    {
        std::vector<int> digits;
        while (n > 0)
        {
            digits.emplace_back(n % 10);
            n /= 10;
        }

        std::reverse(digits.begin(), digits.end());
        return digits;
    }

    int build_int(std::vector<int> &digits)
    {
        int result = 0;
        for (auto &&d : digits)
        {
            result = result * 10 + d;
        }

        return result;
    }

public:
    int maximumSwap(int num)
    {
        auto digits = split(num);
        size_t start = 0;
        while (start < digits.size() - 1)
        {
            size_t max_pos = start;
            int max_el = digits[start];
            for (size_t i = start + 1; i < digits.size(); i++)
            {
                if (digits[i] >= max_el && digits[i] != digits[start])
                {
                    max_el = digits[i];
                    max_pos = i;
                }
            }

            if (max_pos == start)
            {
                start++;
                continue;
            }
            else
            {
                std::swap(digits[max_pos], digits[start]);
                break;
            }
        }

        return build_int(digits);
    }
};
// @lc code=end
