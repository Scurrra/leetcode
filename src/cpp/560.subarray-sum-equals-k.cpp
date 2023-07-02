#include <vector>
#include <unordered_map>

/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 * 
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution
{
public:
    int subarraySum(std::vector<int> &nums, int k)
    {
        int sum = 0, counter = 0;
        std::unordered_map<int, int> sum_dict;
        sum_dict.emplace(std::make_pair(0, 1));
        for (size_t i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum_dict.find(sum - k) != sum_dict.end())
            {
                counter += sum_dict[sum - k];
            }
            sum_dict[sum]++;
        }

        return counter;
    }
};
// @lc code=end
