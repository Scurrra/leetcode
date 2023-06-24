#include <string>

/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    bool isSubsequence(std::string s, std::string t)
    {
        size_t seq_ptr = 0;
        for (size_t i = 0; i < s.size(); i++, seq_ptr++)
        {
            while (seq_ptr < t.size() && t[seq_ptr] != s[i])
            {
                seq_ptr++;
            }

            if (seq_ptr == t.size())
            {
                return false;
            }
            if (seq_ptr == t.size() - 1)
            {
                return i == s.size() - 1;
            }
        }

        return true;
    }
};
// @lc code=end
