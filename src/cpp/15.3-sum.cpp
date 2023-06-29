#include <vector>
#include <algorithm>

/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * Time complexity: O(n log n + n) = O(n log n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                break;
            }

            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0)
                {
                    r--;
                }
                else if (sum < 0)
                {
                    l++;
                }
                else
                {
                    result.push_back({nums[i], nums[l], nums[r]});

                    l++;
                    r--;
                    while (nums[l] == nums[l - 1] && l < r)
                    {
                        l++;
                    }
                }
            }
        }

        return result;
    }
};
// @lc code=end
