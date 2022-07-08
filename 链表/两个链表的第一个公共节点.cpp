class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode *, int> hash_map;
        if (!headA || !headA) {return NULL;}
        
        while (headA || headB) {
            if (headA) {
                if (hash_map.find(headA) != hash_map.end()) {
                    return headA;
                }
                hash_map[headA] = 1;
                headA = headA -> next;
            }

            
            if (headB) {
                if (hash_map.find(headB) != hash_map.end()) {
                    return headB;
                }
                hash_map[headB] = 1;
                headB = headB -> next;
            }
        }
        return NULL;
    }
};