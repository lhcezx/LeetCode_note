//  分治
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* left_node = invertTree(root->left);
        TreeNode* right_node = invertTree(root->right);
        root->left = right_node;
        root->right = left_node;
        return root;
    }
};

//  遍历

class Solution {
public:
    void traverse(TreeNode* root) {
        if (root == nullptr) return;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        traverse(root->left);
        traverse(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        traverse(root);
        return root;
    }
};