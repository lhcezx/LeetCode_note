// 堆

struct cmp {
    bool operator()(ListNode* a, ListNode*b) {
        return a->val > b->val;                 //  最小的值会被放在最后面，pop_back()会直接弹出最小值
    }
};
class Solution {
    priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy_head = new ListNode(-1);
        ListNode* cur = dummy_head;

        for (auto list: lists) {
            if (list != nullptr) heap.push(list);
        }
        while (!heap.empty()) {
            ListNode* top = heap.top();
            heap.pop();
            cur->next = top;
            cur = cur->next;
            if (top->next != nullptr) heap.push(top->next);
        }
        cur->next = nullptr;
        return dummy_head->next;
    }
};


//  归并排序

class Solution {
public:
    ListNode* merge(ListNode* left, ListNode* right) {      //  合并两个有序链表
        ListNode* dummy_head = new ListNode(-1);
        ListNode* cur = dummy_head;
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                cur->next = left;
                left = left->next;
            } else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        if (left != nullptr) cur->next = left;
        else cur->next = right;
        return dummy_head->next;
    }


    ListNode* mergeSort(vector<ListNode*>& lists, int left, int right) {
        if (left >= right) return lists[left];
        int mid = left + (right - left) / 2;
        ListNode* left_node = mergeSort(lists, left, mid);              //  将[left, mid]区间内的所有有序链表合并
        ListNode* right_node = mergeSort(lists, mid + 1, right);        //  将[mid + 1, right]区间内的所有有序链表合并
        return merge(left_node, right_node);
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return mergeSort(lists, 0, lists.size() - 1);
    }
};