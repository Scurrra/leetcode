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
        for (auto &&num : nums)
        {
            counter[num]++;
        }
        
        int answer = 0;
        for (auto &&[_, count] : counter)
        {
            answer += count * (count - 1) / 2;
        }
        
        return answer;
    }
};
// @lc code=end
