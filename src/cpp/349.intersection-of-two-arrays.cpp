#include <vector>
#include <unordered_map>

/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 * 
 * Time complexity: O(n + m)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::unordered_map<int, bool> bag;
        for (auto &&num : nums1)
        {
            bag[num] = false;
        }

        std::vector<int> intersection;
        for (auto &&num : nums2)
        {
            if (bag.find(num) != bag.end() && !bag[num])
            {
                intersection.push_back(num);
                bag[num] = true;
            }
        }

        return intersection;
    }
};
// @lc code=end
