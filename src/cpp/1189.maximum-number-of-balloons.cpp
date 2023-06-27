#include <string>
#include <unordered_map>

/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 * 
 * Time complexity: O(n)
 * Space complexity: O(1) --- map for letter counting
 */

// @lc code=start
class Solution
{
public:
    int maxNumberOfBalloons(std::string text)
    {
        std::unordered_map<char, int> balloon = {
            {'b', 0},
            {'a', 0},
            {'l', 0},
            {'o', 0},
            {'n', 0}};

        for (auto &&c : text)
        {
            if (balloon.find(c) != balloon.end())
            {
                balloon[c]++;
            }
        }

        int max_balloon = std::min(balloon['o'] / 2, balloon['l'] / 2);
        max_balloon = std::min(max_balloon, balloon['b']);
        max_balloon = std::min(max_balloon, balloon['a']);
        max_balloon = std::min(max_balloon, balloon['n']);

        return max_balloon;
    }
};
// @lc code=end
