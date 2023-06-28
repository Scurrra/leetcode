#include <vector>
#include <string>

/*
 * @lc app=leetcode id=2446 lang=cpp
 *
 * [2446] Determine if Two Events Have Conflict
 * 
 * Time complexity: O(1)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
private:
    int toMinutes(std::string &time)
    {
        return std::stoi(time.substr(0, 2)) * 60 + std::stoi(time.substr(3, 2));
    }

public:
    bool haveConflict(std::vector<std::string> &event1, std::vector<std::string> &event2)
    {
        int event1_start = toMinutes(event1[0]), event1_end = toMinutes(event1[1]);
        int event2_start = toMinutes(event2[0]), event2_end = toMinutes(event2[1]);

        if (event2_start <= event1_end && event1_end <= event2_end)
        {
            return true;
        }
        if (event1_start <= event2_end && event2_end <= event1_end)
        {
            return true;
        }

        if (event2_start <= event1_start && event1_end <= event2_end)
        {
            return true;
        }
        if (event1_start <= event2_start && event2_end <= event1_end)
        {
            return true;
        }

        return false;
    }
};
// @lc code=end
