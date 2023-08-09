struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        auto previous = head, start = head->next;
        while (previous != nullptr && start != nullptr && previous->val != start->val && start->next != nullptr && start->val == start->next->val)
        {
            while (start->next != nullptr && start->val == start->next->val)
            {
                start = start->next;
            }
            start = start->next;
            previous->next = start;
        }
        while (start != nullptr && start->next != nullptr && start->next->next != nullptr)
        {
            if (start->next->val == start->next->next->val)
            {
                while (start->next->next != nullptr && start->next->val == start->next->next->val)
                {
                    start->next = start->next->next;
                }
                start->next = start->next->next;
            }
            else
            {
                previous->next = start;
                previous = previous->next;
                start = start->next;
            }
        }
        if (head->next != nullptr && head->val == head->next->val)
        {
            while (head->next != nullptr && head->val == head->next->val)
            {
                head = head->next;
            }
            head = head->next;
        }

        return head;
    }
};
// @lc code=end
