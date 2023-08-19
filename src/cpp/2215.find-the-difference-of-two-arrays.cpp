#include <vector>
#include <unordered_set>

/*
 * @lc app=leetcode id=2215 lang=cpp
 *
 * [2215] Find the Difference of Two Arrays
 * 
 * Time complexity: O(n + m)
 * Space complexity: O(n + m)
 */

// @lc code=start
class Solution
{
public:
    std::vector<std::vector<int>> findDifference(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::unordered_set<int> nums1set(nums1.begin(), nums1.end());
        std::unordered_set<int> nums2set(nums2.begin(), nums2.end());
        std::unordered_set<int> diff12, diff21;

        for (auto &&n : nums1set)
        {
            if (nums2set.find(n) == nums2set.end())
            {
                diff12.emplace(n);
            }
        }

        for (auto &&n : nums2set)
        {
            if (nums1set.find(n) == nums1set.end())
            {
                diff21.emplace(n);
            }
        }

        return {
            std::vector<int>(diff12.begin(), diff12.end()),
            std::vector<int>(diff21.begin(), diff21.end()),
        };
    }
};
// @lc code=end
