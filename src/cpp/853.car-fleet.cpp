#include <vector>
#include <algorithm>

/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 * 
 * Time complexity: O(n log n + n) = O(n log n)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution
{
public:
    int carFleet(int target, std::vector<int> &position, std::vector<int> &speed)
    {
        std::vector<std::pair<int, int>> vehicle(position.size());
        for (size_t i = 0; i < vehicle.size(); i++)
        {
            vehicle[i] = std::make_pair(position[i], speed[i]);
        }
        std::sort(vehicle.begin(), vehicle.end(), [](std::pair<int, int> &left, std::pair<int, int> &right)
                  { return left.first > right.first; });

        std::vector<float> fleets;
        for (auto &&[p, s] : vehicle)
        {
            fleets.push_back((float)(target - p) / s);
            if (fleets.size() > 1 && fleets.back() <= fleets.rbegin()[1])
            {
                fleets.pop_back();
            }
        }

        return fleets.size();
    }
};
// @lc code=end
