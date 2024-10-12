#include <vector>
#include <unordered_map>

/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 *
 * Time: O(n)
 * Space: O(n)
 */

// @lc code=start
class Solution
{
public:
    int numIdenticalPairs(std::vector<int> &nums)
    {
        std::unordered_map<int, int> counter;
        int answer = 0;
        for (auto &&num : nums)
        {
            answer += counter[num];
            counter[num]++;
        }

        return answer;
    }
};
// @lc code=end
