#include <vector>
#include <map>
#include <unordered_map>

/*
 * @lc app=leetcode id=1679 lang=cpp
 *
 * [1679] Max Number of K-Sum Pairs
 */

// @lc code=start
class Solution
{
public:
    int maxOperations(std::vector<int> &nums, int k)
    {
        std::unordered_map<int, int> seen;
        int sum = 0;

        for (auto &&num : nums)
        {
            if (seen.contains(k - num) && seen[k - num] > 0)
            {
                sum++;
                seen[k - num]--;
            }
            else
            {
                seen[num]++;
            }
        }

        return sum;
    }
};
// @lc code=end
