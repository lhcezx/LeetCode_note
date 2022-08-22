/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
    unordered_map<Node*, Node*> hash_map;               //  原链表上的每一个节点和复制链表的每一个节点的映射
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        Node* cur = new Node(head->val);
        Node* dummy_head = new Node(-1);
        dummy_head->next = cur;
        hash_map[head] = cur;
        while (cur != nullptr) {
            if (head->next != nullptr) {                
                if (!hash_map.count(head->next)) {      //  判断是否已经创建过了，例如第一个节点的random可能是第三个节点，当遍历到第二个节点时第三个节点已经创建了，直接从哈希表取值即可
                    cur->next = new Node(head->next->val);
                    hash_map[head->next] = cur->next;
                } else {
                    cur->next = hash_map[head->next];
                }
            } 

            if (head->random != nullptr) {
                if (!hash_map.count(head->random)) {
                    cur->random = new Node(head->random->val);
                    hash_map[head->random] = cur->random;
                } else {
                    cur->random = hash_map[head->random];
                }
            } 
            cur = cur->next;
            head = head->next;
        }
        return dummy_head->next;
    }
};