class Solution {
public:
    ListNode* n_next = NULL;
    ListNode* reversetopN(ListNode* head, int n) {
        if (n == 1) {                         // 当我们找到了第n个节点时
            n_next = head->next;              // 记录第n个节点的下一个节点，目的是反转链表后将反转后的尾节点接到这个节点上构成完整的链表
            return head;                      // 返回第n个节点作为我们翻转后的头节点
        }
        ListNode* last = reversetopN(head->next, n - 1);
        head->next->next = head;              // 逐步将从第n-1到1个节点的后一个节点的指针指向自身, ex: (n-1->next = n, n->next = n-1) == n-1->next->next = n-1
        head->next = n_next;                  // 当最终到达原链表的头节点时，我们让head也就是当前的尾节点指向刚才保存的n_next
        return last;
    }
//  这里的递归解释: 前面的函数reversetopN是反转以head为头节点的前n个节点，这里其实我们想要反转以left为头节点的right - left个节点。
//  我们让head = head->next进行递归，每次递归让left - 1同时让right - 1, 当left减到为1的时候head已经++到left位置的节点变为了head头节点，同时righ在--的循环结果为right - left = n. 这时执行 reversetopN(head, right) 可以理解为以left位置的节点为头节点翻转right - left个节点。
//  当left == 1 return reversetopN(head, right)，返回值为last节点，也就是right节点. right节点不但是reversetopN() 函数的返回值，同时也是最后一层的reversebetween()函数的返回值，
//  head->next = reverseBetween(head->next, left -  1, right - 1) 函数的最后一层返回right节点，然后返回到前一层，前一层的head是left节点的前一个节点，让这个节点的next节点指向不再是left节点而是返回的right节点，至此完成列表的翻转以及对接. (left和右边链表的对接在reversetopN函数中完成，right 和左边的链表对接在reversebetween中完成)
//  
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1) return reversetopN(head, right);   //  如果left为第一个节点起始位，则相当于翻转前right个节点
        head->next = reverseBetween(head->next, left -  1, right - 1);  
        return head;
    }
};