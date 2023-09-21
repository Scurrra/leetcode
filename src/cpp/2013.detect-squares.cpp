#include <vector>
#include <map>
#include <math.h>

/*
 * @lc app=leetcode id=2013 lang=cpp
 *
 * [2013] Detect Squares
 */

// @lc code=start
class DetectSquares
{
private:
    std::map<std::pair<int, int>, int> pcount;
    std::vector<std::pair<int, int>> points;

public:
    DetectSquares()
    {
    }

    void add(std::vector<int> point)
    {
        auto p = std::make_pair(point[0], point[1]);
        pcount[p]++;
        points.emplace_back(p);
    }

    int count(std::vector<int> point)
    {
        int result = 0;
        auto px = point[0], py = point[1];

        for (auto &&[x, y] : points)
        {
            if (std::abs(py - y) != std::abs(px - x) || x == px || y == py)
            {
                continue;
            }

            result += pcount[std::make_pair(x, py)] * pcount[std::make_pair(px, y)];
        }

        return result;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
// @lc code=end
