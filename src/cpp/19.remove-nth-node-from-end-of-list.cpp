struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr)
        {
            return head;
        }
        
        auto tail = head;
        short length = 1;
        while (tail->next != nullptr)
        {
            length++;
            tail = tail->next;
        }
        
        if (n == length)
        {
            return head->next;
        }

        short to_be_removed = length - n;
        short current = 1;
        tail = head;
        while (current < to_be_removed)
        {
            tail = tail->next;
            current++;
        }
        tail->next = tail->next->next;

        return head;
    }
};
// @lc code=end
