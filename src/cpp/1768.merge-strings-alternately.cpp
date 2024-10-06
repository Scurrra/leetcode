#include <string>

/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        std::string answer;
        answer.reserve(word1.size()+word2.size());
        for (size_t i = 0; i < std::min(word1.size(), word2.size()); i++) {
            answer.push_back(word1[i]);
            answer.push_back(word2[i]);
        }
        if (word1.size() < word2.size()) {
            answer.append(word2, word1.size(), word2.size()-word1.size());
        } else if (word2.size() < word1.size()) {
            answer.append(word1, word2.size(), word1.size()-word2.size());
        }
        
        return answer;
    }
};
// @lc code=end

