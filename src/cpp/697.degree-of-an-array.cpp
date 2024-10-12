#include <vector>
#include <map>
#include <algorithm>

/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 * 
 * Time: O(n)
 * Space: O(n)
 */

// @lc code=start
class Solution
{
public:
    int findShortestSubArray(std::vector<int> &nums)
    {
        std::map<int, std::pair<int, std::pair<int, int>>> counter;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (!counter.contains(nums[i]))
            {
                counter[nums[i]] = std::make_pair(1, std::make_pair(i, i));
            }
            else
            {
                counter[nums[i]].first++;
                counter[nums[i]].second.second = i;
            }
        }

        int min_width = 0, max_frequency = 0;
        for (auto &&[_, bounds] : counter)
        {
            if (bounds.first > max_frequency)
            {
                max_frequency = bounds.first;
                min_width = bounds.second.second - bounds.second.first + 1;
            }
            else if (bounds.first == max_frequency)
            {
                min_width = std::min(min_width, bounds.second.second - bounds.second.first + 1);
            }
        }

        return min_width;
    }
};
// @lc code=end
