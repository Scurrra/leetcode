#include <string>

/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 * 
 * Time: O(n)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    int titleToNumber(std::string columnTitle)
    {
        int number = 0;
        for (auto &&c : columnTitle)
        {
            number *= 26;
            number += (int)(c - 'A' + 1); 
        }
        
        return number;
    }
};
// @lc code=end
