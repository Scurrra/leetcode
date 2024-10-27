#include <vector>
#include <algorithm>

/*
 * @lc app=leetcode id=1238 lang=cpp
 *
 * [1238] Circular Permutation in Binary Representation
 * 
 * Time: O(2^n)
 * Space: O(2^n)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> circularPermutation(int n, int start)
    {
        std::vector<int> seq(2 << n - 1);
        // std::generate(
        //     seq.begin(),
        //     seq.end(),
        //     []()
        //     {
        //         static int i = 0;
        //         return i ^ ((i++) >> 1);
        //     });
        for (int i = 0; i < seq.size(); i++)
        {
            seq[i] = i ^ (i >> 1);
        }
        
        std::rotate(
            seq.begin(),
            std::find(seq.begin(), seq.end(), start),
            seq.end());

        return seq;
    }
};
// @lc code=end
