#include <string>

/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution
{
public:
    std::string reverseWords(std::string s)
    {
        size_t left = 0;
        for (size_t right = 0; right < s.size(); right++)
        {
            if (s[right] == ' ' || right == s.size() - 1)
            {
                auto temp_l = left, temp_r = right-1;
                if (right == s.size() - 1)
                {
                    temp_r = right;
                }

                while (temp_l < temp_r)
                {
                    std::swap(s[temp_l], s[temp_r]);
                    temp_l++;
                    temp_r--;
                }

                left = right + 1;
            }
        }

        return s;
    }
};
// @lc code=end
