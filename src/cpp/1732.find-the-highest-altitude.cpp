#include <vector>

/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 * 
 * Time: O(n)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    int largestAltitude(std::vector<int> &gain)
    {
        int level = 0, maxlevel = 0;

        for (auto &&g : gain)
        {
            level += g;
            maxlevel = maxlevel > level ? maxlevel : level;
        }

        return maxlevel;
    }
};
// @lc code=end
