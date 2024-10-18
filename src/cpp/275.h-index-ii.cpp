#include <vector>

/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */

// @lc code=start
class Solution
{
public:
    int hIndex(std::vector<int> &citations)
    {
        int hindex = 0;
        for (int i = citations.size() - 1; i >= 0; i--)
        {
            if (hindex < citations[i])
            {
                hindex++;
            }
            else
            {
                break;
            }
        }

        return hindex;
    }
};
// @lc code=end
