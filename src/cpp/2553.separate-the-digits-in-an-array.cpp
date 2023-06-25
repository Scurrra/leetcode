#include <vector>
#include <algorithm>

/*
 * @lc app=leetcode id=2553 lang=cpp
 *
 * [2553] Separate the Digits in an Array
 * 
 * Time complexity: O(n log num)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> separateDigits(std::vector<int> &nums)
    {
        std::vector<int> digits;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            while (nums[i])
            {
                digits.push_back(nums[i]%10);
                nums[i]/=10;
            }
        }
        std::reverse(digits.begin(), digits.end());
        
        return digits;
    }
};
// @lc code=end
