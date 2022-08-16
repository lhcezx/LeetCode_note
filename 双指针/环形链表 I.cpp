class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            slow = slow->next;          //  慢指针一次走一步
            fast = fast->next->next;    //  快指针一次走两步
            if (slow == fast) return true;  //  若快慢指针相遇，则证明有环，若fast->next或fast为nullptr，则遍历到尾节点，链表不为环状
        }
        return false;
    }
};