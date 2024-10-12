#include <string>

/*
 * @lc app=leetcode id=2390 lang=cpp
 *
 * [2390] Removing Stars From a String
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    std::string removeStars(std::string s)
    {
        size_t i = 0;
        while (i < s.size())
        {
            if (s[i + 1] == '*')
            {
                s.erase(i, 2);
                i = i > 0 ? i - 1 : 0;
            }
            else
            {
                i++;
            }
        }

        return s;
    }
};
// @lc code=end
