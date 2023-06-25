#include <vector>

/*
 * @lc app=leetcode id=2221 lang=cpp
 *
 * [2221] Find Triangular Sum of an Array
 * 
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution
{
public:
    int triangularSum(std::vector<int> &nums)
    {
        std::vector<int> previous(nums);
        std::vector<int> current(nums.size() - 1);

        while (current.size() != 0)
        {
            for (size_t i = 0; i < current.size(); i++)
            {
                current[i] = (previous[i] + previous[i + 1]) % 10;
            }
            previous = current;
            current.pop_back();
        }

        return previous[0];
    }
};
// @lc code=end
