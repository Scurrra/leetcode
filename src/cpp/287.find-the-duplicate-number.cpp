#include <vector>

/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int findDuplicate(std::vector<int> &nums)
    {
        int slow = 0, fast = 0;
        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
            {
                break;
            }
        }

        int floyd = 0;
        while (true)
        {
            slow = nums[slow];
            floyd = nums[floyd];
            if (slow == floyd)
            {
                return floyd;
            }
        }
    }
};
// @lc code=end
