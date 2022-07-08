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
    stack<int> s1, s2;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* next = nullptr;
        while (!s1.empty() || !s2.empty() || carry != 0) {
            int num1 = s1.empty()? 0: s1.top();             //  注意需要分别判断两个栈是否为空
            int num2 = s2.empty()? 0: s2.top();
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
            int num = (num1 + num2 + carry) % 10;
            carry = (num1 + num2 + carry) / 10;
            ListNode* cur = new ListNode(num);
            cur->next = next;
            next = cur;
        }
        return next;
    }
};


