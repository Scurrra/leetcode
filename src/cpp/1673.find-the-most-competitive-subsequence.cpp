#include <vector>

/*
 * @lc app=leetcode id=1673 lang=cpp
 *
 * [1673] Find the Most Competitive Subsequence
 * 
 * Time: O(n)
 * Space: O(n)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> mostCompetitive(std::vector<int> &nums, int k)
    {
        int min = nums[0], mini = 0;
        for (size_t i = 0; i < nums.size() - k + 1; i++)
        {
            if (nums[i] < min)
            {
                min = nums[i];
                mini = i;
            }
        }

        std::vector<int> answer{nums[mini]};
        nums.reserve(nums.size() - mini + 1);
        for (size_t i = mini + 1; i < nums.size(); i++)
        {
            if (answer.back() > nums[i] && k + i < nums.size() + answer.size())
            {
                while (answer.back() > nums[i] && k + i < nums.size() + answer.size())
                {
                    answer.pop_back();
                }
            }
            answer.push_back(nums[i]);
        }

        while (answer.size() > k)
            answer.pop_back();
        return answer;
    }
};
// @lc code=end
