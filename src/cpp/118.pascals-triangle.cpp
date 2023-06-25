#include <vector>

/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * Time complexity: O(n log n)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    std::vector<std::vector<int>> generate(int numRows)
    {
        if (numRows == 1)
        {
            return {{1}};
        }

        std::vector<std::vector<int>> triangle(numRows);
        triangle[0] = {1};

        for (size_t i = 1; i < numRows; i++)
        {
            std::vector<int> row(i + 1, 1);
            for (size_t j = 1; j < i / 2 + 1; j++)
            {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
                row[i - j] = row[j];
            }
            triangle[i] = std::move(row);
        }

        return triangle;
    }
};
// @lc code=end
