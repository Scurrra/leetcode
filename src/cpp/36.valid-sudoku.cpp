#include <vector>
#include <array>

/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 *
 * Let n = 9;
 * Time complexity: O(n^2)
 * Space complexity: O(n)
 */

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char>> &board)
    {
        for (size_t i = 0; i < 9; i++)
        {
            std::vector<char> row(9);
            for (size_t j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    row[j] = 0;
                }
                else
                {
                    row[j] = board[i][j] - '0';
                }
            }
            board[i] = row;
        }

        for (size_t i = 0; i < 9; i++)
        {
            std::vector<bool> row(9, false), column(9, false);
            for (size_t j = 0; j < 9; j++)
            {
                if (row[board[i][j] - 1] || column[board[j][i] - 1])
                {
                    return false;
                }
                if (board[i][j])
                {
                    row[board[i][j] - 1] = true;
                }
                if (board[j][i])
                {
                    column[board[j][i] - 1] = true;
                }
            }
        }

        std::array<std::array<short, 2>, 9> steps{{{0, 0}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}}};
        for (size_t i = 1; i < 8; i += 2)
        {
            for (size_t j = 1; j < 8; j += 2)
            {
                std::vector<bool> subbox(9, false);

                for (auto &&[x, y] : steps)
                {
                    if (!board[i + x][j + y])
                    {
                        continue;
                    }

                    if (subbox[board[i + x][j + y] - 1])
                    {
                        return false;
                    }
                    subbox[board[i + x][j + y] - 1] = true;
                }
            }
        }

        return true;
    }
};
// @lc code=end
