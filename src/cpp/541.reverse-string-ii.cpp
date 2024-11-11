#include <string>

/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
class Solution
{
public:
    std::string reverseStr(std::string s, int k)
    {
        for (size_t start = 0; start < s.size(); start += 2 * k)
        {
            auto left = start;
            auto right = start + k - 1 < s.size() ? start + k - 1 : s.size() - 1;

            while (left < right)
            {
                std::swap(s[left++], s[right--]);
            }
        }

        return s;
    }
};
// @lc code=end
