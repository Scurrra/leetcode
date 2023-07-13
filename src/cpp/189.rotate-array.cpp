#include <vector>

/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution
{
public:
    void rotate(std::vector<int> &nums, int k)
    {
        k = k % nums.size();
        auto m = nums.size() - k;
        nums.reserve(nums.size() + m);
        nums.insert(nums.end(), nums.begin(), nums.begin() + m);
        nums.erase(nums.begin(), nums.begin() + m);
    }
};
// @lc code=end
