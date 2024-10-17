#include <vector>
#include <string>
#include <array>

/*
 * @lc app=leetcode id=1160 lang=cpp
 *
 * [1160] Find Words That Can Be Formed by Characters
 *
 * Time: O(n)
 * Space: O(m), m = words.size()
 */

// @lc code=start
class Solution
{
public:
    int builder(std::array<int, 26> alphabet, std::string &word)
    {
        for (auto &&alpha : word)
        {
            if (alphabet[alpha - 'a'] > 0)
            {
                alphabet[alpha - 'a']--;
            }
            else
            {
                return 0;
            }
        }

        return word.size();
    }

    int countCharacters(std::vector<std::string> &words, std::string &chars)
    {
        std::array<int, 26> alphabet;
        for (auto &&alpha : chars)
        {
            alphabet[alpha - 'a']++;
        }

        int sum = 0;
        for (auto &&word : words)
        {
            sum += builder(alphabet, word);
        }
        return sum;
    }
};
// @lc code=end
