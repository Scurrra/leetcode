#include <vector>

/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 * 
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> nextGreaterElements(std::vector<int> &nums)
    {
        std::vector<int> result(nums.size(), -1);
        for (size_t i = 0; i < nums.size(); i++)
        {
            size_t j = (i + 1) % nums.size();
            while (j != i)
            {
                if (nums[j] > nums[i])
                {
                    result[i] = nums[j];
                    break;
                }
                j = (j + 1) % nums.size();
            }
        }

        return result;
    }
};
// @lc code=end
