#include <vector>
#include <numeric>
#include <algorithm>

/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
class NumArray
{
private:
    std::vector<int> cum;

public:
    NumArray(std::vector<int> &nums)
    {
        this->cum.assign(nums.begin(), nums.end());
        std::partial_sum(
            cum.cbegin(), cum.cend(),
            cum.begin());
    }

    int sumRange(int left, int right)
    {
        return cum[right] -
               (left > 0 ? cum[left - 1] : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
