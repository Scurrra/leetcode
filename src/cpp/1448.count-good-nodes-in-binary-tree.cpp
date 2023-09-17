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
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
    int goodNodes(TreeNode *root)
    {
        std::function<int(TreeNode *, int)> dfs = [&](TreeNode *node, int max)
        {
            if (node == nullptr)
            {
                return 0;
            }

            int result = node->val >= max ? 1 : 0;
            max = std::max(max, node->val);
            return result + dfs(node->right, max) + dfs(node->left, max);
        };

        return dfs(root, root->val);
    }
};
// @lc code=end
