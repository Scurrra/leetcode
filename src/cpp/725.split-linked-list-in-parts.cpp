#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
 * 
 * Time complexity: O(n)
 * Space complexity: O(k)
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
    std::vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        std::vector<ListNode *> result(k);
        if (head == nullptr)
        {
            return result;
        }

        auto start = head;
        int size = 1;
        while (start->next != nullptr)
        {
            size++;
            start = start->next;
        }
        int lens = size / k, tails = size % k;

        start = head;
        for (size_t i = 0; i < k && start != nullptr; i++)
        {
            result[i] = start;
            auto buf = start;
            for (size_t j = 0; j < lens; j++)
            {
                if (j == lens - 1)
                {
                    buf = start;
                }

                start = start->next;
            }
            if (tails != 0)
            {
                buf = start;
                start = start->next;
                tails--;
            }
            buf->next = nullptr;
        }

        return result;
    }
};
// @lc code=end
