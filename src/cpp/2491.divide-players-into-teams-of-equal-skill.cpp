#include <vector>
#include <algorithm>

/*
 * @lc app=leetcode id=2491 lang=cpp
 *
 * [2491] Divide Players Into Teams of Equal Skill
 *
 * Time: O(n log n)
 * Space: O(1) but somehow more than version with std::map
 */

// @lc code=start
class Solution
{
public:
    long long dividePlayers(std::vector<int> &skill)
    {
        std::sort(skill.begin(), skill.end());

        long long chemistry = 0;
        short sum = skill.front() + skill.back();
        for (int i = 0; i < skill.size() / 2; i++)
        {
            if (skill[i] + skill[skill.size() - i - 1] == sum)
            {
                chemistry += skill[i] * skill[skill.size() - i - 1];
            }
            else
            {
                return -1;
            }
        }

        return chemistry;
    }
};
// @lc code=end
