#include <vector>
#include <numeric>

/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int pivotIndex(std::vector<int> &nums)
    {
        int n = nums.size() - 1;
        auto sumleft = 0, sumright = std::accumulate(nums.begin(), nums.end(), 0);
        
        int el = -1, current = 0;
        while (el < n)
        {
            sumleft += current;
            current = nums[++el];
            sumright -= current;

            if (sumleft == sumright)
            {
                return el;
            }
        }

        return -1;
    }
};
// @lc code=end
