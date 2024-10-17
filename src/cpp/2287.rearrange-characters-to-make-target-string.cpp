#include <string>
#include <array>

/*
 * @lc app=leetcode id=2287 lang=cpp
 *
 * [2287] Rearrange Characters to Make Target String
 * 
 * Time: O(n + m)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    int rearrangeCharacters(std::string s, std::string target)
    {
        std::array<int, 26> alphabet;
        for (auto &&alpha : s)
        {
            alphabet[alpha - 'a']++;
        }

        int counter = 0;
        while (true)
        {
            for (auto &&alpha : target)
            {
                if (alphabet[alpha - 'a'] > 0)
                {
                    alphabet[alpha - 'a']--;
                }
                else
                {
                    return counter;
                }
            }
            counter++;
        }

        return 0;
    }
};
// @lc code=end
