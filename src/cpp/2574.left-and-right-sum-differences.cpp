#include <vector>
#include <numeric>
#include <algorithm>

/*
 * @lc app=leetcode id=2574 lang=cpp
 *
 * [2574] Left and Right Sum Differences
 * 
 * Time: O(n)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> leftRightDifference(std::vector<int> &nums)
    {
        int n = nums.size() - 1;
        auto sumleft = 0, sumright = std::accumulate(nums.begin(), nums.end(), 0);
        std::vector<int> diffs(nums.size());

        int el = -1, current = 0;
        while (el < n)
        {
            sumleft += current;
            current = nums[++el];
            sumright -= current;

            diffs[el] = std::abs(sumright-sumleft);
        }

        return diffs;
    }
};
// @lc code=end
