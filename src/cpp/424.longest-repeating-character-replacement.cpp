#include <string>
#include <unordered_map>

/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int characterReplacement(std::string s, int k)
    {
        std::unordered_map<char, int> counter;

        size_t l = 0;
        int maxf = 0, maxl;
        for (size_t r = 0; r < s.size(); r++)
        {
            counter[s[r]]++;
            maxf = std::max(maxf, counter[s[r]]);
            maxl = r - l + 1;
            if ((maxl - maxf) > k)
            {
                counter[s[l++]]--;
                maxl--;
            }
        }

        return maxl;
    }
};
// @lc code=end
