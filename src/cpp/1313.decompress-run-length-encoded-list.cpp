#include <vector>

/*
 * @lc app=leetcode id=1313 lang=cpp
 *
 * [1313] Decompress Run-Length Encoded List
 * 
 * Time: O(n)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> decompressRLElist(std::vector<int> &nums)
    {
        int n = 0;
        for (size_t i = 0; i < nums.size(); i += 2)
        {
            n += nums[i];
        }
        std::vector<int> decompressed(n);

        size_t j = 0;
        for (size_t i = 0; i < nums.size(); i += 2)
        {
            for (size_t k = 0; k < nums[i]; k++)
            {
                decompressed[j++] = nums[i + 1];
            }
        }

        return decompressed;
    }
};
// @lc code=end
