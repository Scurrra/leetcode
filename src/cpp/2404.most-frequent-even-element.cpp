#include <vector>
#include <map>

/*
 * @lc app=leetcode id=2404 lang=cpp
 *
 * [2404] Most Frequent Even Element
 * 
 * Time: O(n)
 * Space: O(n)
 */

// @lc code=start
class Solution
{
public:
    int mostFrequentEven(std::vector<int> &nums)
    {
        std::map<int, int> counter;
        for (auto &&num : nums)
        {
            if (num % 2 == 0)
            {
                counter[num]++;
            }
        }

        int most = 100001, freq = 0;
        for (auto &&[k, c] : counter)
        {
            if ((c > freq) || (c == freq && k < most))
            {
                most = k;
                freq = c;
            }
        }

        return counter.size() == 0 ? -1 : most;
    }
};
// @lc code=end
