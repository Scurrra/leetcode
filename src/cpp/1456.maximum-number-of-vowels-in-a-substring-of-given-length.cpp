#include <string>
#include <unordered_set>

/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 * 
 * Time: O(n)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    int maxVowels(std::string &s, int k)
    {
        std::unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'/*, 'y'*/};

        int cur = 0, max = 0;

        int right = 0;
        for (right = 0; right < k && right < s.size(); right++)
        {
            cur += vowels.contains(s[right]);
        }
        max = cur;

        for (int left = 0; right < s.size(); left++, right++)
        {
            cur -= vowels.contains(s[left]);
            cur += vowels.contains(s[right]);

            max = std::max(cur, max);
        }

        return max;
    }
};
// @lc code=end
