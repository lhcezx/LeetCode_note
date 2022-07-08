class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);         //  虚拟头节点
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        for (int i = 0; i < n + 1; i++) {           //  首先让fast指针走n+1步，则剩下N-n-1步走到尾节点，N为链表总长度包含尾节点
            if (fast) fast = fast->next;
        }
        while (fast != nullptr) {               
            fast = fast->next;
            slow = slow->next;
        }
        if (slow->next) slow->next = slow->next->next;
        return dummy->next;                         //  这里要指向dummy->next而不是head, 因为如果我们删除的节点为head, 那么dummy->next将为空节点而非head节点
    }
};