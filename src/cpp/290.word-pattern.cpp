#include <string>
#include <sstream>
#include <unordered_map>

/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 * 
 * Time: O(n)
 * Space: O(n)
 */

// @lc code=start
class Solution
{
public:
    bool wordPattern(std::string pattern, std::string s)
    {
        std::unordered_map<char, std::string> dictionary;
        std::unordered_map<std::string, char> inverse;
        std::istringstream isstream(s);
        std::string word;
        short i = 0;
        while (isstream >> word)
        {
            if (i == pattern.size())
            {
                return false;
            }
            
            if ((dictionary.contains(pattern[i]) && dictionary[pattern[i]] != word) || (inverse.contains(word) && inverse[word] != pattern[i]))
            {
                return false;
            }
            else
            {
                inverse[word] = pattern[i];
                dictionary[pattern[i]] = word;
            }
            i++;
        }

        return i == pattern.size();
    }
};
// @lc code=end
