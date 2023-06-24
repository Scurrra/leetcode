#include <string>

/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(std::string s)
    {
        size_t s_ptr = s.size() - 1;
        int length = 0;

        while (s_ptr > 0 && s[s_ptr] == ' ')
        {
            s_ptr--;
        }
        while (s_ptr > 0 && s[s_ptr] != ' ')
        {
            length++;
            s_ptr--;
        }
        if (s_ptr == 0)
        {
            length += s[s_ptr] != ' ';
        }

        return length;
    }
};
// @lc code=end
