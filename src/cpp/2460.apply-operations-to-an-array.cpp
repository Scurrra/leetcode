#include <vector>

/*
 * @lc app=leetcode id=2460 lang=cpp
 *
 * [2460] Apply Operations to an Array
 */

// @lc code=start
class Solution
{
private:
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

public:
    std::vector<int> applyOperations(std::vector<int> &nums)
    {
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        moveZeroes(nums);

        return nums;
    }
};
// @lc code=end
