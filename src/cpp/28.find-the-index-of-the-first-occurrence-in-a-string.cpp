#include <string>

/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int strStr(std::string haystack, std::string needle)
    {
        if (haystack.size() < needle.size())
        {
            return -1;
        }
        
        if (haystack.size() == needle.size())
        {
            size_t i = 0;
            while (i < haystack.size() && haystack[i] == needle[i])
            {
                i++;
            }
            return i == haystack.size() ? 0 : -1;
        }

        for (int i = 0; i < haystack.size() - needle.size() + 1; i++)
        {
            if (haystack[i] == needle[0])
            {
                int j = 1;
                while (j < needle.size() && haystack[i + j] == needle[j])
                {
                    j++;
                }
                if (j == needle.size())
                {
                    return i;
                }
            }
        }

        return -1;
    }
};
// @lc code=end
