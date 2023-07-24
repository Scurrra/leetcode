struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
        {
            return head;
        }
        while (head != nullptr && head->val == val)
        {
            head = head->next;
        }
        
        auto tail = head;
        while (tail != nullptr && tail->next != nullptr && tail->next->next != nullptr)
        {
            if (tail->next->val == val)
            {
                tail->next = tail->next->next;
            }
            else 
            {
                tail = tail->next;
            }
        }
        if (tail != nullptr && tail->next != nullptr && tail->next->val == val)
        {
            tail->next = nullptr;
        }
        
        return head;
    }
};
// @lc code=end
