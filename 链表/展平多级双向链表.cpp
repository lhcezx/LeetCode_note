/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->child == nullptr) cur = cur->next;
            else {
                Node* next = cur->next;             //  当前节点的下一个节点
                Node* child_head = cur->child;      //  当前节点的子链表的头节点
                Node* child_tail = nullptr;         //  子链表的尾节点
                while (child_head != nullptr && child_head->next != nullptr) {
                    child_head = child_head->next;
                }
                child_tail = child_head;
                cur->next = cur->child;         // 当前节点的下一个节点接上child节点
                cur->child->prev = cur;         // child节点的上一个节点接到cur节点
                cur->child = nullptr;
                if (next) {
                    child_tail->next = next;
                    next->prev = child_tail;
                }

            }
        }
        return head;
    }
};