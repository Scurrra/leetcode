#include <vector>
#include <unordered_map>

/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 * 
 * Let n = nums2.size(), m = nums1.size()
 * Time complexity: O(n + m n)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::unordered_map<int, size_t> nums2_inv(nums2.size());
        for (size_t i = 0; i < nums2.size(); i++)
        {
            nums2_inv.emplace(std::make_pair(nums2[i], i));
        }

        std::vector<int> result(nums1.size(), -1);
        for (size_t i = 0; i < nums1.size(); i++)
        {
            size_t j = nums2_inv[nums1[i]] + 1;
            while (j < nums2.size())
            {
                if (nums2[j] > nums1[i])
                {
                    result[i] = nums2[j];
                    break;
                }
                j++;
            }
        }

        return result;
    }
};
// @lc code=end
