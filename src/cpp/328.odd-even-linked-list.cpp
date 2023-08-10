#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        auto tail = head;
        auto length = 1;
        while (tail->next != nullptr)
        {
            tail = tail->next;
            length++;
        }

        auto start = head;
        while (length > length % 2 && start->next->next != nullptr)
        {
            tail->next = start->next;
            tail = tail->next;

            start->next = start->next->next;
            start = start->next;

            length -= 2;
        }
        tail->next = nullptr;

        return head;
    }
};
// @lc code=end
