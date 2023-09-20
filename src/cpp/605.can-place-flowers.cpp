#include <vector>

/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    bool canPlaceFlowers(std::vector<int> &flowerbed, int n)
    {
        int empty = flowerbed[0] ? 0 : 1;
        for (auto &&f : flowerbed)
        {
            if (f)
            {
                n -= (empty - 1) / 2;
                empty = 0;
            }
            else
            {
                empty++;
            }
        }

        n -= empty / 2;
        return n <= 0;
    }
};
// @lc code=end
