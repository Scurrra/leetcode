#include <vector>
#include <unordered_set>

/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequences
 * 
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution
{
public:
    int longestConsecutive(std::vector<int> &nums)
    {
        std::unordered_set<int> nums_set(nums.begin(), nums.end());
        int longest = 0;
        for (auto &&num : nums)
        {
            if (nums_set.find(num - 1) == nums_set.end())
            {
                int length = 1;
                while (nums_set.find(num + length) != nums_set.end())
                {
                    length++;
                }
                longest = std::max(length, longest);
            }
        }

        return longest;
    }
};
// @lc code=end
