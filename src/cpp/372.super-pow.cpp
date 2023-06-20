#include <vector>

/*
 * @lc app=leetcode id=372 lang=cpp
 *
 * [372] Super Pow
 * 
 * Time complexity: O(n log n) -- O(n) for division and O(log n) for binpow
 * Space complexity: O(1)
 */

// @lc code=start
void vec_decrease(std::vector<int> &vec)
{
    if (vec[vec.size() - 1] != 0)
    {
        vec[vec.size() - 1]--;
    }
    else
    {
        size_t dec_by_one = vec.size() - 1;
        while (dec_by_one && !vec[dec_by_one])
        {
            vec[dec_by_one--] = 9;
        }
        vec[dec_by_one]--;
    }

    while (!vec.empty() && vec[0] == 0)
    {
        vec.erase(vec.begin());
    }
}

void vec_half(std::vector<int> &vec)
{
    if (vec.empty() || vec[vec.size() - 1] % 2)
    {
        return;
    }

    for (int i = vec.size() - 1; i >= 1; i--)
    {
        if (vec[i - 1] % 2)
        {
            vec[i] = (10 + vec[i]) / 2;
            vec[i - 1]--;
        }
        else
        {
            vec[i] /= 2;
        }
    }
    vec[0] /= 2;

    while (!vec.empty() && vec[0] == 0)
    {
        vec.erase(vec.begin());
    }
}

class Solution
{
public:
    int superPow(int a, std::vector<int> &b)
    {
        int result = 1;
        a %= 1337;
        while (!b.empty())
        {
            if (b[b.size()-1] % 2)
            {
                result = result * a % 1337;
                vec_decrease(b);
            }
            a = a * a % 1337;
            vec_half(b);
        }
        return result;
    }
};
// @lc code=end
