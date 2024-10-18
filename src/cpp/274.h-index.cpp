#include <vector>
#include <map>
#include <algorithm>

/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */

// @lc code=start
class Solution
{
public:
    int hIndex(std::vector<int> &citations)
    {
        // std::map<int, int> counter;
        // int max = 0;
        int max = *std::max_element(citations.begin(), citations.end());
        std::vector<int> counter(max+1);
        for (auto &&c : citations)
        {
            counter[c]++;
            // max = c > max ? c : max;
        }

        int hindex = 0;
        for (int i = max; i > 0; i--)
        {
            // if (counter.contains(i))
            // {
                if (hindex < i)
                {
                    while (counter[i] > 0 && hindex < i)
                    {
                        hindex++;
                        counter[i]--;
                    }
                }
                else
                {
                    break;
                }
            // }
        }

        return hindex;
    }
};
// @lc code=end
