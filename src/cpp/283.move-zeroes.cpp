#include <vector>

/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(std::vector<int> &nums)
    {
        size_t most_left_zero = 0;
        while (most_left_zero < nums.size() && nums[most_left_zero] != 0)
            most_left_zero++;
        size_t most_left_nonzero = most_left_zero;
        while (most_left_nonzero < nums.size() && nums[most_left_nonzero] == 0)
            most_left_nonzero++;

        while (most_left_nonzero < nums.size())
        {
            std::swap(nums[most_left_nonzero], nums[most_left_zero]);
            while (most_left_zero < nums.size() && nums[most_left_zero] != 0)
                most_left_zero++;
            most_left_nonzero = most_left_zero;
            while (most_left_nonzero < nums.size() && nums[most_left_nonzero] == 0)
                most_left_nonzero++;
        }
    }
};
// @lc code=end
