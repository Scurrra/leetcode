#include <vector>
#include <numeric>
#include <cstdint>

/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 *
 * Time: O(n)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    double findMaxAverage(std::vector<int> &nums, int k)
    {
        if (nums.size() == k)
        {
            return static_cast<double>(std::accumulate(nums.begin(), nums.end(), 0)) / k;
        }

        int64_t sum = std::accumulate(nums.begin(), nums.begin() + k, 0);

        int64_t maxSum = sum;
        for (size_t i = k; i < nums.size(); i++)
        {
            maxSum = std::max(maxSum, (nums[i] - nums[i - k]) + sum);
            sum = (nums[i] - nums[i - k]) + sum;
        }

        return static_cast<double>(maxSum) / k;
    }
};
// @lc code=end
