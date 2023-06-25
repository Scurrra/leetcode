#include <string>
#include <vector>

/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 * 
 * Time complexity: O(nm), n --- strs.size(), m --- result.size()
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        std::string result("");
        size_t prefix_ptr = 0;
        while (true)
        {
            char current_char = strs[0][prefix_ptr];
            for (auto &&str : strs)
            {
                if (prefix_ptr == str.size() || str[prefix_ptr] != current_char)
                {
                    return result;
                }
            }
            result += current_char;
            prefix_ptr++;
        }

        return result;
    }
};
// @lc code=end
