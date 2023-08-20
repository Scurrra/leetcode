#include <vector>

/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    bool canJump(std::vector<int> &nums)
    {
        int goal = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (i + nums[i] >= goal)
            {
                goal = i;
            }
        }

        return goal == 0;
    }
};
// @lc code=end
