#include <vector>
#include <algorithm>

/*
 * @lc app=leetcode id=1984 lang=cpp
 *
 * [1984] Minimum Difference Between Highest and Lowest of K Scores
 * 
 * Time complexity: O(n log n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int minimumDifference(std::vector<int> &nums, int k)
    {
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        auto l = 0, r = k - 1;
        auto diff = 0x3f3f3f;
        while (r < nums.size())
        {
            diff = std::min(diff, nums[l] - nums[r]);
            l++;
            r++;
        }

        return diff;
    }
};
// @lc code=end
