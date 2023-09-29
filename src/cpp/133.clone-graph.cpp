#include <functional>
#include <unordered_map>
#include <vector>

class Node
{
public:
    int val;
    std::vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = std::vector<Node *>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = std::vector<Node *>();
    }

    Node(int _val, std::vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        std::unordered_map<Node *, Node *> mapping;
        std::function<Node *(Node *)> dfs = [&](Node *node)
        {
            if (mapping.find(node) != mapping.end())
            {
                return mapping[node];
            }

            auto copy = new Node(node->val);
            mapping[node] = copy;
            for (auto &&n : node->neighbors)
            {
                copy->neighbors.emplace_back(dfs(n));
            }

            return copy;
        };

        return dfs(node);
    }
};
// @lc code=end
