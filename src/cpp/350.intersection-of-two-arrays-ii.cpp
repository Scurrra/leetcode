#include <vector>
#include <unordered_map>

/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::unordered_map<int, int> bag;
        for (auto &&num : nums1)
        {
            bag[num]++;
        }

        std::vector<int> intersection;
        for (auto &&num : nums2)
        {
            if (bag.find(num) != bag.end() && bag[num])
            {
                intersection.push_back(num);
                bag[num]--;
            }
        }

        return intersection;
    }

};
// @lc code=end

