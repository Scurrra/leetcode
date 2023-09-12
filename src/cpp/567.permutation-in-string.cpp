#include <string>
#include <array>

/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * Time complexity: O(n)
 * Space complexity: O(26) = O(1)
 */

// @lc code=start
class Solution
{
public:
    bool checkInclusion(std::string s1, std::string s2)
    {
        if (s1.size() > s2.size())
        {
            return false;
        }

        std::array<int, 26> s1Letters, s2Letters;
        std::fill(s1Letters.begin(), s1Letters.end(), 0);
        std::fill(s2Letters.begin(), s2Letters.end(), 0);
        for (size_t i = 0; i < s1.size(); i++)
        {
            s1Letters[s1[i] - 'a']++;
            s2Letters[s2[i] - 'a']++;
        }

        int matches = 0;
        for (size_t i = 0; i < 26; i++)
        {
            matches += s1Letters[i] == s2Letters[i] ? 1 : 0;
        }

        size_t left = 0;
        for (size_t right = s1.size(); right < s2.size(); right++, left++)
        {
            if (matches == 26)
            {
                return true;
            }

            auto index = s2[right] - 'a';
            s2Letters[index]++;
            if (s1Letters[index] == s2Letters[index])
            {
                matches++;
            }
            else if (s1Letters[index] + 1 == s2Letters[index])
            {
                matches--;
            }

            index = s2[left] - 'a';
            s2Letters[index]--;
            if (s1Letters[index] == s2Letters[index])
            {
                matches++;
            }
            else if (s1Letters[index] - 1 == s2Letters[index])
            {
                matches--;
            }
        }

        return matches == 26;
    }
};
// @lc code=end
