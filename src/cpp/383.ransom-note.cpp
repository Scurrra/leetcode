#include <string>
#include <array>

/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 * 
 * Time: O(n)
 * Space: O(26) = O(1)
 */

// @lc code=start
class Solution
{
public:
    bool canConstruct(std::string &ransomNote, std::string &magazine)
    {
        std::array<int, 26> alphabet;
        for (auto &&alpha : magazine)
        {
            alphabet[alpha - 'a']++;
        }

        for (auto &&alpha : ransomNote)
        {
            if (alphabet[alpha - 'a'] > 0)
            {
                alphabet[alpha - 'a']--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
