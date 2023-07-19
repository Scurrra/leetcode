#include <unordered_map>
#include <array>
#include <string>

/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 *
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    std::string intToRoman(int num)
    {
        std::array<short, 7> values{{1000, 500, 100, 50, 10, 5, 1}};
        std::unordered_map<short, char> int2rom{{{1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}}};

        std::string roman = "";
        auto vi = 0;
        while (num && vi < 7)
        {
            auto buf = num / values[vi];
            if (buf == 4 && vi != 0)
            {
                roman += int2rom[values[vi]];
                roman += int2rom[values[vi - 1]];
            }
            else
            {
                for (size_t i = 0; i < buf; i++)
                {
                    roman += int2rom[values[vi]];
                }
            }

            num %= values[vi];
            vi++;
        }

        // DCD -> CM
        if (auto found = roman.find("DCD"); found != std::string::npos)
        {
            roman.replace(found, 3, "CM");
        }

        // LXL -> XC
        if (auto found = roman.find("LXL"); found != std::string::npos)
        {
            roman.replace(found, 3, "XC");
        }

        // VIV -> IX
        if (auto found = roman.find("VIV"); found != std::string::npos)
        {
            roman.replace(found, 3, "IX");
        }

        return roman;
    }
};
// @lc code=end
