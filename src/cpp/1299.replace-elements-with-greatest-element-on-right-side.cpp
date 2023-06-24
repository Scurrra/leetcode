#include <vector>

/*
 * @lc app=leetcode id=1299 lang=cpp
 *
 * [1299] Replace Elements with Greatest Element on Right Side
 *
 * Time complexity: O(n)
 * Space complexity: O(1), because result vector isn't counted
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> replaceElements(std::vector<int> &arr)
    {
        std::vector<int> result(arr.size());
        result[result.size() - 1] = -1;
        int curr_max = arr[arr.size() - 1];
        for (int i = arr.size() - 1; i > 0; i--)
        {
            if (curr_max < arr[i])
            {
                curr_max = arr[i];
            }
            result[i - 1] = curr_max;
        }

        return result;
    }
};
// @lc code=end
