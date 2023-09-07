#include <limits.h>

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
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool validate(TreeNode *node, long left, long right)
    {
        if (node == nullptr)
        {
            return true;
        }
        if (!(left < node->val && node->val < right))
        {
            return false;
        }

        return validate(node->left, left, node->val) &&
               validate(node->right, node->val, right);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return validate(root, (long)INT_MIN - 1, (long)INT_MAX + 1);
    }
};
// @lc code=end
