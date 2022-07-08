/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int sum = 0;
public:
    void traverse(TreeNode* root) {
        if (root == nullptr) return;
        traverse(root->right);
        sum += root->val;
        root->val = sum;
        traverse(root->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        traverse(root);
        return root;
    }
};