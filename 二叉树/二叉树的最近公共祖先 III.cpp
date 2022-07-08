/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* i = p;
        Node* j = q;
        while (i != j) {
            if (i == nullptr) i = q;
            else i = i->parent;
            if (j == nullptr) j = p;
            else j = j->parent;
        }
        return i;
    }
};