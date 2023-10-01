#include <vector>
#include <algorithm>

/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 * 
 * Time complexity: O(n log n + n) = O(n log n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int numRescueBoats(std::vector<int> &people, int limit)
    {
        std::sort(people.begin(), people.end());

        int boats = 0;
        int left = 0, right = people.size() - 1;
        while (left <= right)
        {
            if (people[left] + people[right] <= limit)
            {
                left++;
            }
            right--;
            boats++;
        }

        return boats;
    }
};
// @lc code=end
