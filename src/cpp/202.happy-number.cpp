#include <set>
#include <vector>
#include <numeric>

/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution
{
private:
    std::vector<int> digits_inverse(int n)
    {
        std::vector<int> digs;
        while (n > 0)
        {
            digs.push_back(n % 10);
            n /= 10;
        }

        return digs;
    }

public:
    bool isHappy(int n)
    {
        std::set<int> history;
        size_t history_size = history.size();

        history.insert(n);
        while (history_size != history.size())
        {
            history_size = history.size();
            auto digits = digits_inverse(n);
            n = std::accumulate(
                digits.begin(), digits.end(),
                0, [](int sum, int d)
                { return sum + d * d; });

            if (n == 1)
            {
                return true;
            }
            history.insert(n);
        }

        return false;
    }
};
// @lc code=end
