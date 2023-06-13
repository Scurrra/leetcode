#include <string>

/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(std::string s)
    {
        size_t left = 0, right = s.length()-1, last = s.length()-1;
        while (left < last && !isalnum(s[left])) left++;
        while (right > 0 && !isalnum(s[right])) right--;
        
        while (left < right && left < last && right > 0)
        {
            if (tolower(s[left]) == tolower(s[right]))
            {
                left++;
                right--;
                while (!isalnum(s[left])) left++;
                while (!isalnum(s[right])) right--;
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
};
// @lc code=end
