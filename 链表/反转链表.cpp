class Solution {
    ListNode* n_prev;
    
public:
    ListNode* reverseList(ListNode* head) {
        n_prev = nullptr;
        while(head != nullptr) {
            ListNode* tmp = head->next;
            head->next = n_prev;
            n_prev = head;
            head = tmp;
        }

        return n_prev;
        
    }
};