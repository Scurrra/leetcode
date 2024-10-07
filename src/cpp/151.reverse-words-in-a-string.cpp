#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution
{
public:
    std::string reverseWords(std::string s)
    {
        // there is a two pinters solution, but idk
        std::vector<std::string> words;
        std::istringstream isstream(s);
        std::string buf;
        while (isstream >> buf) words.emplace_back(buf);
        return std::accumulate(
            std::next(words.rbegin()),
            words.rend(),
            words.back(),
            [](auto a, auto b)
            { return a + " " + b; });
    }
};
// @lc code=end
