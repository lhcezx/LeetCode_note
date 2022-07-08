/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head == nullptr) return nullptr;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;                      //  slow每次走一步
            fast = fast->next->next;                //  fast每次走两步 
            if (slow == fast) break;
        }

        if (fast->next == nullptr || fast->next->next == nullptr) return nullptr;
        fast = head;
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};