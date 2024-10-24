#include <string>
#include <algorithm>

/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 * 
 * Time: O(log(n))
 * Space: O(log(n))
 */

// @lc code=start
class Solution
{
public:
    std::string convertToTitle(int columnNumber)
    {
        std::string title = "";
        while (columnNumber != 0)
        {
            title += (char)(65 + (columnNumber - 1) % 26);
            columnNumber = (columnNumber - 1) / 26;
        }

        std::reverse(title.begin(), title.end());
        return title;
    }
};
// @lc code=end
