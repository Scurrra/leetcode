#include <vector>
#include <queue>

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
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * Time complexity: O(n)
 * Space complexity: O(n)
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
    std::vector<std::vector<int>> levelOrder(TreeNode *root)
    {
        std::vector<std::vector<int>> result;
        std::queue<TreeNode *> q;

        if (root != nullptr)
            q.push(root);
        while (!q.empty())
        {
            auto len = q.size();
            std::vector<int> level(len);
            for (size_t i = 0; i < len; i++)
            {
                auto node = q.front();
                q.pop();

                level[i] = node->val;
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            result.emplace_back(std::move(level));
        }

        return result;
    }
};
// @lc code=end
