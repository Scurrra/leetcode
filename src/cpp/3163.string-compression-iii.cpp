#include <vector>
#include <string>
#include <cstdint>

/*
 * @lc app=leetcode id=3163 lang=cpp
 *
 * [3163] String Compression III
 */

// @lc code=start
class Solution
{
public:
    std::string compressedString(std::string word)
    {
        std::string compressed = "";

        int count = 0;
        char symbol = word[0];
        for (size_t i = 0; i < word.size(); i++)
        {
            if (word[i] == symbol && count < 9)
            {
                count++;
            }
            else
            {
                compressed += std::to_string(count) + symbol;
                count = 1;
                symbol = word[i];
            }
        }

        compressed += std::to_string(count) + symbol;

        return compressed;
    }
};
// @lc code=end
