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
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode *root)
    {
        int result = root->val;

        std::function<int(TreeNode *)> dfs = [&](TreeNode *root)
        {
            if (root == nullptr)
            {
                return 0;
            }

            auto left = std::max(0, dfs(root->left));
            auto right = std::max(0, dfs(root->right));

            result = std::max(result, left + root->val + right);
            return root->val + std::max(left, right);
        };

        auto _ = dfs(root);
        return result;
    }
};
// @lc code=end
