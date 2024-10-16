#include <vector>
#include <numeric>

/*
 * @lc app=leetcode id=1991 lang=cpp
 *
 * [1991] Find the Middle Index in Array
 * 
 * Time: O(n)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    int findMiddleIndex(std::vector<int> &nums)
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
