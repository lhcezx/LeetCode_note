/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void traverse (Node* left, Node* right){
        if (left == nullptr) return;
        left->next = right;
        traverse(left->left, left->right);
        traverse(right->left, right->right);
        traverse(left->right, right->left);
    }

    Node* connect(Node* root) {
        if (root == nullptr) return root;
        traverse(root->left, root->right);
        return root;
    }
};