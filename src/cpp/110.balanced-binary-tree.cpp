#include <functional>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        std::function<std::pair<bool, int>(TreeNode *)> dfs = [&](TreeNode *root)
        {
            if (root == nullptr)
            {
                return std::make_pair(true, 0);
            }

            auto left = dfs(root->left);
            auto right = dfs(root->right);

            return std::make_pair(
                left.first && right.first && std::abs(left.second - right.second) < 2,
                1 + std::max(left.second, right.second));
        };

        return dfs(root).first;
    }
};
// @lc code=end
