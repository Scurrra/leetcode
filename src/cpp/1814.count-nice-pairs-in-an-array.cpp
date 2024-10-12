#include <vector>
#include <unordered_map>
#include <cstdint>

/*
 * @lc app=leetcode id=1814 lang=cpp
 *
 * [1814] Count Nice Pairs in an Array
 * 
 * Time: O(n) // reverse in O(10)
 * Space: O(n)
 */

// @lc code=start
class Solution
{
public:
    uint64_t countNicePairs(std::vector<int> &nums)
    {
        std::unordered_map<int64_t, uint64_t> counter;
        uint64_t answer = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            uint64_t buf = 0; 
            int64_t num = nums[i];
            while (num > 0)
            {
                buf = buf * 10 + num % 10;
                num /= 10;
            }

            num = nums[i] - buf;
            answer = (answer + counter[num]) % 1000000007;
            counter[num]++;
        }

        return answer;
    }
};
// @lc code=end
