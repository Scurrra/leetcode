#include <vector>
#include <string>
#include <unordered_map>
#include <array>
#include <functional>
#include <cstdint>

/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 * 
 * Time complexity: O(k*n)
 * Space complexity: O(k*n)
 */

// @lc code=start
struct AlphabetHash 
{
    size_t operator()(std::array<uint8_t, 26> letters) const
    {
        size_t h = 0;
        for (auto &&l : letters)
        {
            h ^= std::hash<uint8_t>()(l);
        }
        return h;
    }
};

class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {
        std::unordered_map<std::array<uint8_t, 26>, std::vector<std::string>, AlphabetHash> anagrams;
        for (const std::string& str : strs)
        {
            std::array<uint8_t, 26> str_letters = {};
            for (auto&& c : str)
            {
                str_letters[c - 'a']++;
            }

            anagrams[str_letters].push_back(std::move(str));
        }

        std::vector<std::vector<std::string>> anagram_groups;
        for (auto &anagram : anagrams)
        {
            anagram_groups.push_back(std::move(anagram.second));
        }
        
        return anagram_groups;
    }
};
// @lc code=end
