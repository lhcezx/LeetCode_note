//  若相交，链表A： a+c, 链表B : b+c. a+c+b = b+c+a 。则会在公共处c起点相遇。若不相交，a +b = b+a 。因此相遇处是NULL
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while (p1 != p2) {
            if (p1 == nullptr) p1 = headB;
            else p1 = p1->next;
            if (p2 == nullptr) p2 = headA;
            else p2 = p2->next;
            }
        return p1;
    }
};
