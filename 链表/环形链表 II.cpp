//假设相遇点距离环开始的位置距离为m, 则从启始位置head到环开始的位置距离为k-m，恰巧从相遇位置走到环开始的位置距离也是k-m(因为k是环的长度的整数倍，m是因为从环的起点到相遇点已经走了m步，因此只需要走k-m步就能回到环的起点), 因此当两个指针以同样的速度相遇时即找到环的起始点。


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;  
        ListNode* slow = head;
        //  while循环的终止条件有两个: 
        //  1. fast或fast->next == nullptr，这种情况证明链表无环
        //  2. fast和slow相遇，break语句退出while循环
        while (fast && fast->next) {
            slow = slow->next;              //  慢指针一次走一步
            fast = fast->next->next;        //  快指针一次走两步
            if (fast == slow) break;        
        }
        if (fast == nullptr || fast->next == nullptr) return nullptr; // 该情况为while循环终止的第一种情况，返回nullptr;
        fast = head;                                                  // 反之为第二种情况，使fast指向头节点
        while (fast != slow && fast && slow) {
            fast = fast->next;                                        // 让fast和slow以同样的速度移动，当他们相遇时相遇的节点即为环的启始节点。
            slow = slow->next;
        }
        return slow;
    }
};