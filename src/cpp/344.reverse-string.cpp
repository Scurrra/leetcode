#include <vector>

/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 * 
 * Time complexity: O(n)
 * Space complexity:  O(1)
 */

// @lc code=start
class Solution
{
public:
    void reverseString(std::vector<char> &s)
    {
        size_t n = s.size();
        for (size_t i = 0; i < n/2; i++)
        {
            char buf = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = buf;
        }
    }
};
// @lc code=end
