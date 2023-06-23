#include <vector>

/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 * 
 * Time complexity: O(n m / 4) = O(nm)
 * Space complexity: O(1)
 */

// @lc code=start
class Solution
{
public:
    void rotate(std::vector<std::vector<int>> &matrix)
    {
        for (size_t i = 0; i < matrix.size() / 2; i++)
        {
            for (size_t j = i; j < matrix.size() - i - 1; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[matrix.size() - j - 1][i];
                matrix[matrix.size() - j - 1][i] = matrix[matrix.size() - i - 1][matrix.size() - j - 1];
                matrix[matrix.size() - i - 1][matrix.size() - j - 1] = matrix[j][matrix.size() - i - 1];
                matrix[j][matrix.size() - i - 1] = temp;
            }
        }
    }
};
// @lc code=end
