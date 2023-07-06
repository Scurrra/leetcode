#include <string>
#include <unordered_set>

/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 * 
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_set<char> seq;
        int left = 0;
        int seq_length = 0;

        for (int right = 0; right < s.size(); right++)
        {
            while (seq.find(s[right]) != seq.end())
            {
                seq.erase(s[left++]);
            }
            
            seq.insert(s[right]);
            seq_length = std::max(seq_length, right - left + 1);
        }
        
        return seq_length;
    }
};
// @lc code=end
