#include <vector>
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
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode *buildTree(std::vector<int> preorder, std::vector<int> inorder)
    {
        if (preorder.empty() || inorder.empty())
        {
            return nullptr;
        }
        
        auto middle = std::find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        return new TreeNode(
            preorder[0],
            buildTree(std::vector<int>(preorder.begin()+1, preorder.begin()+middle+1), std::vector<int>(inorder.begin(), inorder.begin()+middle)),
            buildTree(std::vector<int>(preorder.begin()+middle+1, preorder.end()), std::vector<int>(inorder.begin()+middle+1, inorder.end()))
        );
    }
};
// @lc code=end
