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
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int i = 1;                                      //  i用来表示到目前一共有多少个节点，初始情况为1因为只有head节点
        int res = 0;
        ListNode* tmp = head;
        while (tmp != nullptr) {
        //  只有当随机数等于0时 (1 / i)的当前概率，我们才会将res替换为当前指针指向的节点的值
        //  当我们走到第i个节点时，我们有1 / i的概率选择当前元素，如果要一直保证当i == n时仍然是当前这个元素，那就代表后面的每一个节点我们都不选，也就是(1 - 1/(i+1)) * (1 - 1/(i+2)) * (1 - 1/(i+3))...直到1 - 1 / n，这些乘积最后的结果为 1 / n, 也就是说我们选择了第i个节点的元素并且保留作为最终结果的概率为1 / n
            if (rand() % i == 0) res = tmp->val;        
            tmp = tmp->next;
            i++;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */