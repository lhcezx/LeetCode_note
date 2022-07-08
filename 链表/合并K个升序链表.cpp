// 本题思路为将list中的每个头节点即每个链表的最小值节点放入最小堆中，堆顶元素为k个链表的头节点中最小的头节点，通过迭代将头节点出队然后将其子节点放入堆中，堆会自动将其他链表的头节点和其子节点排序，最小值节点仍在堆顶。不断的将每一个子节点压入堆中，并出堆，直至堆为空。

class Solution {
public:
    //  自定义比较函数，根据节点的值从小到大排序，实现最小堆
    class comp {
    public:
        bool operator() (ListNode* a, ListNode* b){
            if (a && b) return a->val > b->val;  // 按照从小到大
            return true;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        ListNode* head = new ListNode(-1);
        ListNode* p = head;                 // 双指针
        for(ListNode* node: lists) {
            if (node) pq.push(node);                  //将lists中的每个链表头节点放到最小堆中  
        }

        while (!pq.empty()) {  
            ListNode* tmp = pq.top();   // 取出堆中最小值的节点
            pq.pop();
            if (p && tmp) {
                p->next = tmp;          
                if (tmp->next) pq.push(tmp->next);
                p = p->next;
            }

        }
        return head->next;
        
    }
};