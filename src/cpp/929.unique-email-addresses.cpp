#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <iostream>

/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
 */

// @lc code=start
class Solution
{
public:
    int numUniqueEmails(std::vector<std::string> &emails)
    {
        std::set<std::string> unique;

        for (auto &&email : emails)
        {   
            auto bitch = email.find("@");
            if (auto plus = email.find("+"); plus != std::string::npos && plus < bitch)
            {
                email.erase(plus, bitch - plus);
            }

            bitch = email.find("@");
            email.erase(std::remove(email.begin(), email.begin() + bitch, '.'), email.begin() + bitch);
            
            unique.insert(std::move(email));
        }

        return unique.size();
    }
};
// @lc code=end
