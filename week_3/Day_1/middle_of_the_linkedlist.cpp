class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* walker = head;
        ListNode* runner = head;

        while (runner != nullptr && runner->next != nullptr) {
            walker = walker->next;
            runner = runner->next->next;
        }

        return walker;
    }
};