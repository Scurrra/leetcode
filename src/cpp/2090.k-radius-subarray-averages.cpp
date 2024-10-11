#include <vector>
#include <numeric>
#include <cstdint>

/*
 * @lc app=leetcode id=2090 lang=cpp
 *
 * [2090] K Radius Subarray Averages
 * 
 * Time: O(n)
 * Space: O(1) // `avgs` is returned so it doesn't count
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> getAverages(std::vector<int> &nums, int k)
    {
        if (k == 0)
        {
            return nums;
        }

        int len = 2 * k + 1;
        std::vector<int> avgs(nums.size(), -1);
        if (nums.size() < len)
        {
            return avgs;
        }

        uint64_t sum = std::accumulate(nums.begin(), nums.begin() + len, (uint64_t)0);
        for (size_t i = k; i < nums.size() - k - 1; i++)
        {
            avgs[i] = (sum / len);
            sum = (nums[i + k + 1] - nums[i - k]) + sum;
        }
        avgs[nums.size() - k - 1] = (sum / len);

        return avgs;
    }
};
// @lc code=end
