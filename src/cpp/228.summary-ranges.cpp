#include <vector>
#include <string>

/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
private:
    std::string make_range(int a, int b)
    {
        if (a == b)
        {
            return std::to_string(a);
        }
        
        return std::to_string(a) + "->" + std::to_string(b);
    }

public:
    std::vector<std::string> summaryRanges(std::vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return {};
        }
        if (nums.size() == 1)
        {
            return {std::to_string(nums[0])};
        }

        std::vector<std::string> ranges;
        size_t left = 0, right = 0;
        while (left < nums.size() && right < nums.size())
        {
            if (right == nums.size() - 1)
            {
                ranges.emplace_back(make_range(nums[left], nums[right]));
                break;
            }

            if (nums[right] + 1 == nums[right + 1])
            {
                right++;
            } 
            else
            {
                ranges.emplace_back(make_range(nums[left], nums[right]));
                left = right + 1;
                right = left;
            }
        }

        return ranges;
    }
};
// @lc code=end
