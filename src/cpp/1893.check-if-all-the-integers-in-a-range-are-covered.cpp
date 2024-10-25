#include <vector>

/*
 * @lc app=leetcode id=1893 lang=cpp
 *
 * [1893] Check if All the Integers in a Range Are Covered
 * 
 * Time: O(n m) (n = right-left+1, m = ranges.size())
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    bool isCovered(std::vector<std::vector<int>> &ranges, int left, int right)
    {
        for (int i = left; i <= right; i++)
        {
            bool captured = false;
            for (auto &&range : ranges)
            {
                if (range[0] <= i && i <= range[1])
                {
                    i = range[1];
                    captured = true;
                    break;
                }
            }
            if (!captured)
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
