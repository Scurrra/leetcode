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
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
    std::vector<int> rightSideView(TreeNode *root)
    {
        std::vector<int> result;
        std::queue<TreeNode *> queue{{root}};

        while (!queue.empty())
        {
            TreeNode *right = nullptr;
            auto qsize = queue.size();
            for (size_t i = 0; i < qsize; i++)
            {
                auto node = queue.front();
                queue.pop();

                if (node != nullptr)
                {
                    right = node;
                    queue.push(node->left);
                    queue.push(node->right);
                }
            }

            if (right != nullptr)
            {
                result.emplace_back(right->val);
            }
        }

        return result;
    }
};
// @lc code=end
