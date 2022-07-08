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

// 

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* last = reverseList(head->next); // last 节点始终不变，即为链表的尾节点，每次递归返回的节点都是该节点
        head->next->next = head;                  // 当我们遍历到最后一个节点的时候会直接返回因为next == NULL, 返回后的函数中的head为倒数第二个节点，我们需要让head->next即最后一个结点的的next指针指向倒数第二个节点即head;
        head->next = NULL;                        // 这个语句是为了当我们回到了链表的头结点的时候，需要让链表的头指针指向Null
        return last;
    }
};