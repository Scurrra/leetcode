#include <string>
#include <set>

/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    std::string reverseVowels(std::string s)
    {
        if (s.size() < 2)
        {
            return s;
        }
        
        std::set<char> vowels{{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}}; // but not 'y'
        size_t left = 0, right = s.size() - 1;

        while (left < s.size() - 1 && vowels.find(s[left]) == vowels.end())
            left++;
        while (right > 0 && vowels.find(s[right]) == vowels.end())
            right--;

        while (left < right)
        {
            std::swap(s[left], s[right]);

            left++;
            right--;
            while (left < s.size() - 1 && vowels.find(s[left]) == vowels.end())
                left++;
            while (right > 0 && vowels.find(s[right]) == vowels.end())
                right--;
        }

        return s;
    }
};
// @lc code=end
