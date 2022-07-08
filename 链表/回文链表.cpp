class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* newhead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != nullptr) slow = slow->next;  // 当fast节点存在，说明fast->next节点不存在，说明链表长度为奇数。此时slow为链表的正中间节点，然而我们想要slow为后半链表的第一个节点，为了方便后续和head的值进行判断，因此slow = slow->next
        ListNode* right = reverse(slow);
        ListNode* left = head;
        while (right != nullptr) {
            if (right->val != left->val) return false;
            right = right->next;
            left = left->next;
        }
        return true;
    }
};