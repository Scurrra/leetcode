#include <string>

/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */

// @lc code=start
class Solution
{
public:
    bool rotateString(std::string s, std::string goal)
    {
        if (s.size() != goal.size())
        {
            return false;
        }
        if (s.size() <= 1)
        {
            return s == goal;
        }
        
        size_t shift = 0;
        while (shift < s.size())
        {
            if (s == goal)
            {
                return true;
            }
            s = s.substr(1) + s[0];
            shift++;
        }
        
        return false;
    }
};
// @lc code=end
