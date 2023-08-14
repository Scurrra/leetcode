#include <unordered_map>
#include <vector>

/*
 * @lc app=leetcode id=554 lang=cpp
 *
 * [554] Brick Wall
 */

// @lc code=start
class Solution
{
public:
    int leastBricks(std::vector<std::vector<int>> &wall)
    {
        std::unordered_map<int, int> cumwall;
        for (auto &&line : wall)
        {
            int cum = 0;
            for (size_t i = 0; i < line.size() - 1; i++)
            {
                cum += line[i];
                cumwall[cum]++;
            }
        }

        int max = 0;
        for (auto &&[k, v] : cumwall)
        {
            if (v > max)
            {
                max = v;
            }
        }

        return wall.size() - max;
    }
};
// @lc code=end
