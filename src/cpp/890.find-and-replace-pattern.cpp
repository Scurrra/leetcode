#include <string>
#include <unordered_map>
#include <vector>

/*
 * @lc app=leetcode id=890 lang=cpp
 *
 * [890] Find and Replace Pattern
 * 
 * Time: O(n m)
 * Space: O(n m)
 */

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(std::string &s, std::string &t)
    {
        std::unordered_map<char, char> mapper;
        for (short i = 0; i < s.size(); i++)
        {
            if (mapper.contains(s[i]) && mapper[s[i]] != t[i])
            {
                return false;
            }
            mapper[s[i]] = t[i];
        }

        mapper.clear();
        for (short i = 0; i < s.size(); i++)
        {
            if (mapper.contains(t[i]) && mapper[t[i]] != s[i])
            {
                return false;
            }
            mapper[t[i]] = s[i];
        }

        return true;
    }

    std::vector<std::string> findAndReplacePattern(std::vector<std::string> &words, std::string pattern)
    {
        std::vector<std::string> answer;
        for (auto &&word : words)
        {
            if (isIsomorphic(word, pattern))
            {
                answer.emplace_back(word);
            }
        }

        return answer;
    }
};
// @lc code=end
