#include <vector>

/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int jump(std::vector<int> &nums)
    {
        int l = 0, r = 0;
        int numOfJumps = 0;
        while (r < nums.size() - 1)
        {
            int maxJump = 0;
            for (int i = l; i < r + 1; i++)
            {
                maxJump = std::max(maxJump, i + nums[i]);
            }

            l = r + 1;
            r = maxJump;
            numOfJumps++;
        }

        return numOfJumps;
    }
};
// @lc code=end
