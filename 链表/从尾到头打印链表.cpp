class Solution {
    vector<int> res;
public:
    void recur(ListNode* head) {
        if (head != nullptr) {
            recur(head->next);
            res.push_back(head->val);
        }
    }
    vector<int> reversePrint(ListNode* head) {
        recur(head);
        return res;
    }
};