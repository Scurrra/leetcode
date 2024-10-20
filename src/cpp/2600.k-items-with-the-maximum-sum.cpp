/*
 * @lc app=leetcode id=2600 lang=cpp
 *
 * [2600] K Items With the Maximum Sum
 * 
 * Time: O(1)
 * Space: O(1)
 */

// @lc code=start
class Solution
{
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
    {
        short sum = numOnes <= k ? numOnes : k;

        // 1s
        k -= sum;
        // 0s
        k -= numZeros <= k ? numZeros : k;
        // -1s        
        sum -= k;

        return sum;
    }
};
// @lc code=end
