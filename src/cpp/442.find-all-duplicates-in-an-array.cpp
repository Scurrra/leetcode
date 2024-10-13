#include <unordered_map>
#include <vector>

/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 * 
 * Time: O(n)
 * Space: O(n)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> findDuplicates(std::vector<int> &nums)
    {
        std::vector<int> duplicates;
        std::unordered_map<int, int> counter;

        for (auto &&num : nums)
        {
            counter[num]++;
            if (counter[num] == 2)
            {
                duplicates.emplace_back(num);
                counter.erase(num);
            }
        }

        return duplicates;
    }
};
// @lc code=end
