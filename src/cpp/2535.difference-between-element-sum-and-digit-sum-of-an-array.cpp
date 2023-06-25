#include <vector>

/*
 * @lc app=leetcode id=2535 lang=cpp
 *
 * [2535] Difference Between Element Sum and Digit Sum of an Array
 * 
 * Time complexity: O(n log num)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int differenceOfSum(std::vector<int> &nums)
    {
        int nums_sum = 0;
        int digits_sum = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            nums_sum += nums[i];
            while (nums[i])
            {
                digits_sum += nums[i] % 10;
                nums[i] /= 10;
            }
        }

        return nums_sum - digits_sum;
    }
};
// @lc code=end
