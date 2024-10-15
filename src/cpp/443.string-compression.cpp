#include <vector>
#include <string>
#include <cstdint>

/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
class Solution
{
public:
    int compress(std::vector<char> &chars)
    {
        char c = chars[0];
        uint16_t counter = 0;
        uint16_t rle = 0;
        for (uint16_t i = 0; i < chars.size(); i++)
        {
            if (chars[i] == c)
            {
                counter++;
            }
            else
            {
                chars[rle++] = c;
                if (counter != 1)
                {
                    auto count = std::to_string(counter);
                    for (uint16_t j = 0; j < count.size(); j++)
                    {
                        chars[rle++] = count[j];
                    }
                }
                counter = 1;
                c = chars[i];
            }
        }

        chars[rle++] = c;
        if (counter != 1)
        {
            auto count = std::to_string(counter);
            for (uint16_t j = 0; j < count.size(); j++)
            {
                chars[rle++] = count[j];
            }
        }

        return rle;
    }
};
// @lc code=end
