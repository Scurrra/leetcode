#include <vector>
#include <unordered_map>

/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 * 
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution
{
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, size_t> map;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (map.count(nums[i]))
            {
                if (i - map[nums[i]] <= k)
                    return true;
            }
            map[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end
