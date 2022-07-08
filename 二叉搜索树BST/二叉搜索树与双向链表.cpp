class Solution {
    Node* prev;
    Node* head;
public:

    void dfs(Node* curr) {
        if (!curr) return;
        dfs(curr->left);
        if (prev) prev->right = curr;
        else head = curr; 
        curr->left = prev;
        prev = curr;
        dfs(curr->right);
    }

    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        dfs(root);
        head->left = prev;
        prev->right = head;
        return head;
    }
};