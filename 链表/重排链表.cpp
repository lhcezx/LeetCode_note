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
    ListNode* FindMid(ListNode* head) {        //  找到链表中心点函数
        ListNode* slow = head;      
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {     // 反转链表函数
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }

    void reorderList(ListNode* head) {
        ListNode* mid = FindMid(head);                  // 找到链表中心点
        ListNode* l1 = head;                            // 左半链表的头节点
        ListNode* l2 = reverseList(mid->next);          // 将链表中心点后半部分链表翻转并获得心的头节点
        mid->next = nullptr;                            // 中心点将变为重组后的链表的最后一个节点，因此需要将其连接到尾节点
        while (l1 != nullptr && l2 != nullptr) {
            ListNode* tmp1 = l1->next;                  // 左半链表的头节点的下一个节点
            ListNode* tmp2 = l2->next;                  // 右半链表的头节点的下一个节点
            l1->next = l2;                              // 将左头接到右头，
            l1 = tmp1;                                  // 左头右移
            l2->next = l1;                              // 将右头接到移动后的左头
            l2 = tmp2;                                  // 右头右移，往复该操作   
        }
    }
};