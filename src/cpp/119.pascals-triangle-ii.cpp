#include <vector>

/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 * 
 * Time complexity: O(n log n)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution
{
public:
    std::vector<int> getRow(int rowIndex)
    {
        if (rowIndex == 0)
        {
            return {{1}};
        }

        std::vector<int> row(rowIndex+1, 1);
        std::vector<int> new_row(rowIndex+1, 1);

        for (size_t i = 1; i <= rowIndex; i++)
        {
            for (size_t j = 1; j < i / 2 + 1; j++)
            {
                new_row[j] = row[j - 1] + row[j];
                new_row[i - j] = new_row[j];
            }
            row = new_row;
        }

        return row;
    }
};
// @lc code=end
