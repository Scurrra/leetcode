/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 * 
 * Time complexity: O(1)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0)
        {
            return false;
        }
        
        return n > 0 && (n & (n - 1)) == 0;
    }
};
// @lc code=end

