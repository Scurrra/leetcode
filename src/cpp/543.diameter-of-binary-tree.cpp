#include <functional>
#include <algorithm>

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
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
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
    int diameterOfBinaryTree(TreeNode *root)
    {
        int result = 0;

        std::function<int(TreeNode *)> dfs = [&](TreeNode *root)
        {
            if (root == nullptr)
            {
                return -1;
            }

            auto left = dfs(root->left);
            auto right = dfs(root->right);
            result = std::max(result, left + right + 2);

            return 1 + std::max(left, right);
        };

        auto _ = dfs(root);
        return result;
    }
};
// @lc code=end
