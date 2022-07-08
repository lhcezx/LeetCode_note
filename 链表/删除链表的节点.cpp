class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* prev;
        ListNode* curr = head;
        if (curr->val == val && head) {head = head->next;}
        while (curr->val != val) {
            prev = curr;
            curr = curr->next;
        }
        if (prev && curr) prev->next = curr->next;
        return head;
    }
};