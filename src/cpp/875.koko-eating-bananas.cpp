#include <vector>
#include <algorithm>
#include <math.h>

/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 * 
 * Time complexity: O(n log n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    int minEatingSpeed(std::vector<int> &piles, int h)
    {
        int result = *std::max_element(piles.begin(), piles.end());
        int left = 1, right = result;

        while (left <= right)
        {
            int middle = (left + right) / 2;

            long total_time = 0;
            for (auto &&pile : piles)
            {
                total_time += std::ceil((double)pile / middle);
            }

            if (total_time <= h)
            {
                result = std::min(result, middle);
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        return result;
    }
};
// @lc code=end
