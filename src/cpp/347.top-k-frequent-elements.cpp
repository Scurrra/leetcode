#include <vector>
#include <unordered_map>

/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int> &nums, int k)
    {
        std::unordered_map<int, int> counter;
        for (size_t i = 0; i < nums.size(); i++)
        {
            counter[nums[i]]++;
        }

        std::vector<std::vector<int>> freqs(nums.size() + 1);
        for (auto &&[num, freq] : counter)
        {
            freqs[freq].push_back(num);
        }

        std::vector<int> result;
        for (int i = freqs.size() - 1; i >= 0; i--)
        {
            if (!freqs.empty())
            {
                result.insert(result.end(), freqs[i].begin(), freqs[i].end());
            }

            if (result.size() == k)
            {
                break;
            }
        }

        return result;
    }
};
// @lc code=end
