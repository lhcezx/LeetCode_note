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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy_head1 = new ListNode(-1);
        ListNode* dummy_head2 = new ListNode(-1);
        ListNode* p1 = dummy_head1;
        ListNode* p2 = dummy_head2;
        while (head != nullptr) {
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
            } else {
                p2->next = head;
                p2 = p2->next;
            }
            //  这里需要注意，将head接到p1或者p2的next指针以后，需要断掉head->next指针，保证p1或p2后面接的仅仅是head节点，而不是从head到nullptr这根链表
            ListNode* tmp = head->next;
            head->next = nullptr;
            head = tmp;
        } 
        p1->next = dummy_head2->next;
        return dummy_head1->next;
    }
};