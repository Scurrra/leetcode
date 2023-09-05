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
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 * 
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (q->val < p->val)
        {
            auto temp = q;
            q = p;
            p = temp;
        }

        auto result = root;
        while (!(p->val <= result->val && result->val <= q->val))
        {
            if (p->val >= result->val)
            {
                result = result->right;
            }
            else if (q->val <= result->val)
            {
                result = result->left;
            }
        }

        return result;
    }
};
// @lc code=end
