#include <vector>
#include <algorithm>
#include <cmath>

/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 * 
 * Time complexity: O(n + n log n + k) = O(n log n)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution
{
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points, int k)
    {
        std::vector<std::pair<size_t, double>> distances(points.size());
        for (size_t i = 0; i < points.size(); i++)
        {
            distances[i] = std::make_pair(
                i,
                std::sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]));
        }

        std::sort(
            distances.begin(), distances.end(),
            [](auto dista, auto distb)
            {
                return dista.second < distb.second;
            });

        std::vector<std::vector<int>> closest(k);
        for (size_t i = 0; i < k; i++)
        {
            closest[i] = points[distances[i].first];
        }
        return closest;
    }
};
// @lc code=end
