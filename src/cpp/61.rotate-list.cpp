/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */

// @lc code=start
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        
        auto tail = head;
        auto length = 1;
        while (tail->next)
        {
            tail = tail->next;
            length++;
        }
        
        k %= length;
        k = length - k;
        while (k)
        {
            tail->next = head;
            tail = tail->next;
            head = head->next;
            k--;
        }
        tail->next = nullptr;

        return head;
    }
};
// @lc code=end
