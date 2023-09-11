#include <unordered_map>

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 * 
 * Time complexity: O(n)
 * Space complexity: O(n)
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        std::unordered_map<Node *, Node *> map{{{nullptr, nullptr}}};

        auto current = head;
        while (current != nullptr)
        {
            auto copy = new Node(current->val);
            map[current] = copy;
            current = current->next;
        }

        current = head;
        while (current != nullptr)
        {
            auto copy = map[current];
            copy->next = map[current->next];
            copy->random = map[current->random];
            current = current->next;
        }

        return map[head];
    }
};
// @lc code=end
