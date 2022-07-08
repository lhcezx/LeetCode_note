class Solution {
public:
    // a为头节点，当a遇到b节点时，返回a节点的前一个节点，函数的作用是将[a, b)区间内的节点反转，注意区间为左闭右开
    ListNode* reverseK(ListNode* a, ListNode* b) {
        ListNode* prev = nullptr;
        ListNode* curr = a;
        ListNode* next;
        while (curr != b) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return head;
        ListNode* a = head;
        ListNode* b = head;

        for (int i = 0; i < k; i++) {       // 遍历循环子链表，如果子链表节点数不足k个，则不翻转，直接返回head. 若子链表满足k个节点，则b最终为位置k的节点。
            if (b == nullptr) return head;  
            b = b->next;
        }
        ListNode* newhead = reverseK(a, b);    // 将[a, b) 内的节点翻转, 函数返回反转后的头节点，作为新子链表的头节点
        head->next = reverseKGroup(b, k);        // 此时的head变为翻转后的链表的尾节点，需要将该尾节点与后面的子链表的头节点相连
        return newhead;
    }
};