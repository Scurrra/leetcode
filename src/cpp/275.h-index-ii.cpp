#include <vector>

/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 * 
 * Time: O(log n)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    int hIndex(std::vector<int> &citations)
    {
        int hindex = 0, n = citations.size();
        int left = 0, right = n - 1, middle;
        while (left <= right)
        {
            middle = left + (right - left) / 2;
            if (citations[middle] >= n - middle)
            {
                hindex = n - middle;
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        return hindex;
    }
};
// @lc code=end
