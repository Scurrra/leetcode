struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode *head)
    {
        auto slow = head, fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second part
        auto second = slow->next;
        slow->next = nullptr;
        ListNode *prev = nullptr;
        while (second != nullptr)
        {
            auto temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        // merge
        auto first = head;
        second = prev;
        while (second != nullptr)
        {
            auto temp1 = first->next, temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};
// @lc code=end
