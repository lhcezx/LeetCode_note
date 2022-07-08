/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);
        if (head == nullptr) {      //  如果链表中不存在节点，则插入节点并形成自环后返回
            node->next = node;
            return node;
        }
        if (head->next == head) {
            node->next = head;      //  如果环中只有一个节点，则可以随意的插入一个新节点
            head->next = node;
            return head;
        }

        Node *cur = head, *next = head->next;       //  此时分析当环内节点大于等于2时
        while (next != head) {                      //  防止重复循环
            if (cur->val <= insertVal && next->val >= insertVal) {      //  当insertval刚好在前后两个节点之间
                break;
            }
            if (cur->val > next->val) {                                 //  当当前节点比下一个节点值大，说明到了最大值节点和最小值节点的临界处 
                if (insertVal > cur->val || insertVal < next->val) {
                    break;
                }
            }
            cur = cur->next;
            next = next->next;
        }
        //  上述的任何一种情况都满足插入条件，如果上述条件都不满足，则说明链表的值相等，因此直接在cur和next中间插入即可
        cur->next = node;
        node->next = next;
        return head;
    }
};