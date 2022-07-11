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
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {      //  找到中间靠前的那个节点，
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* right_head = slow->next;                                  //  记录中间靠后的那个节点
        slow->next = nullptr;                                               //  设置前半段链表的尾节点
        return right_head;
    }

    ListNode* merge(ListNode* left, ListNode* right) {                      
        ListNode* dummy_head = new ListNode(-1);
        ListNode* dummy = dummy_head;
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                dummy_head->next = left;
                left = left->next;
            } else {
                dummy_head->next = right;
                right = right->next;
            }
            dummy_head = dummy_head->next;
        }

        if (left != nullptr) dummy_head->next = left;
        if (right != nullptr) dummy_head->next = right;
        return dummy->next;
    }

    ListNode* mergeSort(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* mid = getMid(head);
        ListNode* left_start = mergeSort(head);                              //  将前半段链表排好序并获得其头节点
        ListNode* right_start = mergeSort(mid);                              //  将后半段链表排好序并获得其头节点
        return merge(left_start, right_start);                               //  将前后两段排好序的链表合并
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return head;
        return mergeSort(head);
        
    }
};

