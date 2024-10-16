#include <vector>
#include <numeric>
#include <cstdint>

/*
 * @lc app=leetcode id=2270 lang=cpp
 *
 * [2270] Number of Ways to Split Array
 * 
 * Time: O(n)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    int waysToSplitArray(std::vector<int> &nums)
    {
        int n = nums.size() - 1;
        int64_t sumleft = nums[0], sumright = std::accumulate(nums.begin() + 1, nums.end(), (int64_t)0);
        int count = 0;

        int el = 0, current = 0;
        while (el < n)
        {
            sumleft += current;
            count += sumleft >= sumright;
            current = nums[++el];
            sumright -= current;
        }

        return count;
    }
};
// @lc code=end
