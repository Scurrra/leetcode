#include <vector>

/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 * 
 * Time complexity: O(n + m)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
    {
        while (n > 0 && m > 0)
        {
            if (nums1[m - 1] > nums2[n - 1])
            {
                nums1[n + m - 1] = nums1[m - 1];
                m--;
            }
            else
            {
                nums1[n + m - 1] = nums2[n - 1];
                n--;
            }
        }
        if (n > 0)
        {
            for (size_t i = 0; i < n; i++)
            {
                nums1[i] = nums2[i];
            }
        }
    }
};
// @lc code=end
