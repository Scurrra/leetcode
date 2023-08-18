struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *sum = new ListNode();
        auto result = sum;
        auto buf = 0;

        while (l1 != nullptr && l2 != nullptr)
        {
            sum->next = new ListNode(l1->val + l2->val + buf);
            buf = sum->next->val / 10;
            sum->next->val %= 10;

            sum = sum->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != nullptr)
        {
            sum->next = new ListNode(l1->val + buf);
            buf = sum->next->val / 10;
            sum->next->val %= 10;

            sum = sum->next;
            l1 = l1->next;
        }

        while (l2 != nullptr)
        {
            sum->next = new ListNode(l2->val + buf);
            buf = sum->next->val / 10;
            sum->next->val %= 10;

            sum = sum->next;
            l2 = l2->next;
        }

        if (buf!=0)
        {
            sum->next = new ListNode(buf);
        }

        return result->next;
    }
};
// @lc code=end
