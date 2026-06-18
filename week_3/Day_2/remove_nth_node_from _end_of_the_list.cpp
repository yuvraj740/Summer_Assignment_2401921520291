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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode helper(0);
        helper.next = head;

        ListNode* lead = &helper;
        ListNode* follow = &helper;

        for (int i = 0; i <= n; ++i) {
            lead = lead->next;
        }

        while (lead) {
            lead = lead->next;
            follow = follow->next;
        }

        ListNode* target = follow->next;
        follow->next = target->next;

        return helper.next;
    }
};