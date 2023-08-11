#include <string>
#include <unordered_map>

/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * Time complexity: O(n)
 * Space complexity: O(n) but < 256
 */

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(std::string s, std::string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        std::unordered_map<char, char> mapper_s, mapper_t;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (mapper_s.find(s[i]) == mapper_s.end() && mapper_t.find(t[i]) == mapper_t.end())
            {
                mapper_s[s[i]] = t[i];
                mapper_t[t[i]] = s[i];
            }
            else if (mapper_s.find(s[i]) != mapper_s.end() && mapper_t.find(t[i]) != mapper_t.end())
            {
                if (mapper_s[s[i]] != t[i] || mapper_t[t[i]] != s[i])
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
// Alternative
// class Solution
// {
// public:
//     bool isIsomorphic(std::string s, std::string t)
//     {
//         if (s.size() != t.size())
//         {
//             return false;
//         }
// 
//         std::unordered_map<char, char> mapper;
//         for (size_t i = 0; i < s.size(); i++)
//         {
//             if (mapper.find(s[i]) == mapper.end())
//             {
//                 mapper[s[i]] = t[i];
//             }
//             else
//             {
//                 if (mapper[s[i]] != t[i])
//                 {
//                     return false;
//                 }
//             }
//         }
// 
//         mapper.clear();
//         for (size_t i = 0; i < t.size(); i++)
//         {
//             if (mapper.find(t[i]) == mapper.end())
//             {
//                 mapper[t[i]] = s[i];
//             }
//             else
//             {
//                 if (mapper[t[i]] != s[i])
//                 {
//                     return false;
//                 }
//             }
//         }
// 
//         return true;
//     }
// };
// @lc code=end
