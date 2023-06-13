#include <string>
#include <array>

/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 * 
 * Space complexity: O(52) = O(1)
 * Time complexity: O(n + 26) = O(n)
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length())
        {
            return false;
        }

        std::array<int, 26> s_letters = {}, t_letters = {};
        for (size_t i = 0; i < s.length(); i++)
        {
            s_letters[s[i]-'a']++;
            t_letters[t[i]-'a']++;
        }
        
        for (size_t i = 0; i < 26; i++)
        {
            if (s_letters[i] != t_letters[i])
            {
                return false;
            }
        }
        
        return true;
    }
};
// @lc code=end

