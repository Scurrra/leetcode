#include <vector>

/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int missingNumber(std::vector<int> &nums)
    {
        int checker;
        // https://www.geeksforgeeks.org/calculate-xor-1-n/
        switch (nums.size() % 4)
        {
        case 0:
            checker = nums.size();
            break;
        case 1:
            checker = 1;
            break;
        case 2:
            checker = nums.size() + 1;
            break;
        case 3:
            checker = 0;
            break;

        default:
            break;
        }
        checker ^= 0;

        for (size_t i = 0; i < nums.size(); i++)
        {
            checker ^= nums[i];
        }

        return checker;
    }
};
// @lc code=end
