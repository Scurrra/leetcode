/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 * 
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */

// @lc code=start
// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        if (n == 1)
        {
            return isBadVersion(1) ? 1 : 0;
        }

        long l = 1, r = n;
        while (l != r && l != r - 1)
        {
            auto m = (l + r) / 2;
            if (isBadVersion(m))
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }

        return isBadVersion(l) ? l : r;
    }
};
// @lc code=end
