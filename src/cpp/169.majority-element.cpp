#include <vector>

/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 * 
 * Moore's Voting Algorithm
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        int answer = 0;
        int counter = 0;

        for (auto &num : nums)
        {
            if (counter == 0)
            {
                answer = num;
            }

            counter += answer == num ? 1 : -1;
        }

        return answer;
    }
};
// @lc code=end
