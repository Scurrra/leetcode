#include <vector>
#include <queue>

/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
 * 
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution
{
public:
    void duplicateZeros(std::vector<int> &arr)
    {
        if (arr.size() == 1)
        {
            return;
        }

        size_t start = 0;
        while (start < arr.size() && arr[start] != 0)
        {
            start++;
        }

        std::queue<int> q;
        for (size_t i = start; i < arr.size() && q.size() < arr.size() - start; i++)
        {
            q.push(arr[i]);
            if (arr[i] == 0)
            {
                q.push(0);
            }
        }

        for (size_t i = start; i < arr.size() && !q.empty(); i++)
        {
            arr[i] = q.front();
            q.pop();
        }
    }
};
// @lc code=end
