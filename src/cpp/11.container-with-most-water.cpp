#include <vector>

/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int area = 0;

        while (l < r)
        {
            area = std::max(area, std::min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
            {
                l++;
            }
            else if (height[l] >= height[r])
            {
                r--;
            }
        }

        return area;
    }
};
// @lc code=end
