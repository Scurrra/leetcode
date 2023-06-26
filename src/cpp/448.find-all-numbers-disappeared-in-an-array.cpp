#include <vector>

/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> findDisappearedNumbers(std::vector<int> &nums)
    {
        for (auto &&num : nums)
        {
            size_t i = (num < 0 ? -num : num) - 1;
            nums[i] = -1 * (nums[i] < 0 ? -nums[i] : nums[i]);
        }

        std::vector<int> dis;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                dis.push_back(i + 1);
            }
        }

        return dis;
    }
};
// @lc code=end
