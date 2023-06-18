#include <vector>

/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &numbers, int target)
    {
        int left = 0, right = numbers.size() - 1;

        while (left < right)
        {
            int sum = numbers[left] + numbers[right];

            if (sum > target)
            {
                right--;
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                return std::vector<int>({++left, ++right});
            }
        }

        return std::vector<int>();
    }
};
// @lc code=end
