class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr) {
            if (slow->val != fast->val) {
                slow->next = fast;
                slow = fast;
            }      
            fast = fast->next;  
        }
        slow->next = nullptr;
        return head;
    }
};