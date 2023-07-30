#include <string>
#include <unordered_map>

/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 * 
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(std::string s) 
    {
        std::unordered_map<char, int> counter;
        for (auto &&c : s)
        {
            counter[c]++;
        }
            
        int length = 0;
        bool single_char = false;
        for (auto &[key, value] : counter)
        {
            length += value / 2;
            single_char = single_char || value % 2 == 1;
        }
        
        return (length << 1) + single_char;
    }
};
// @lc code=end

