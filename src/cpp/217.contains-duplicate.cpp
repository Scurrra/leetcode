#include <vector>
#include <set>

/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 *
 * Time complexity: O(n^2) brute and O(n) with sets
 * Space complexity: O(1) brute and O(n) with sets
 */

// @lc code=start
class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        // // brute
        // for (size_t i = 0; i < nums.size()-1; i++)
        // {
        //     for (size_t j = i+1; j < nums.size(); j++)
        //     {
        //         if (nums[i] == nums[j])
        //         {
        //             return true;
        //         }
        //     }
        // }
        // return false;

        // sets
        std::set<int> nums_set(nums.begin(), nums.end());
        return nums.size() == nums_set.size() ? false : true;
    }
};
// @lc code=end
