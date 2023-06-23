#include <vector>

/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * Time complexity: O(nm)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    void setZeroes(std::vector<std::vector<int>> &matrix)
    {
        bool zero_row = false, zero_col = false;
        // check zeros
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (j > 0)
                    {
                    matrix[0][j] = 0;
                    }
                    else
                    {
                        zero_col = true;
                    }

                    if (i > 0)
                    {
                        matrix[i][0] = 0;
                    }
                    else
                    {
                        zero_row = true;
                    }
                }
            }
        }

        // zeros in non-zero rows
        for (size_t i = 1; i < matrix.size(); i++)
        {
            if (matrix[i][0] == 0)
            {
                for (size_t j = 1; j < matrix[i].size(); j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // zeros in non-zero cols
        for (size_t j = 1; j < matrix[0].size(); j++)
        {
            if (matrix[0][j] == 0)
            {
                for (size_t i = 1; i < matrix.size(); i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // other zeros
        if (matrix[0][0] == 0)
        {
            for (size_t i = 0; i < matrix.size(); i++)
            {
                matrix[i][0] = 0;
            }

            for (size_t j = 0; j < matrix[0].size(); j++)
            {
                matrix[0][j] = 0;
            }
        }
        if (zero_row)
        {
            for (size_t j = 0; j < matrix[0].size(); j++)
            {
                matrix[0][j] = 0;
            }
        }
        if (zero_col)
        {
            for (size_t i = 0; i < matrix.size(); i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
// @lc code=end
