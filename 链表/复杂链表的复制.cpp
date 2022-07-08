class Solution {
    unordered_map<Node*, Node*> hash_map;
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr){
            return nullptr;
        }

        if (!hash_map.count(head)) {
            Node* new_head = new Node(head->val);
            hash_map[head] = new_head;
            new_head->next = copyRandomList(head->next);
            new_head->random = copyRandomList(head->random);
        }
        return hash_map[head];
    }
};