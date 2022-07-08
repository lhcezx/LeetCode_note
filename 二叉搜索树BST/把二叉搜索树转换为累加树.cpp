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
        //  左根右为BST的升序遍历，右根左为BST的降序遍历
        traverse(root->right);          //  首先遍历根的右子树
        sum += root->val;
        root->val = sum;
        traverse(root->left);           //  然后遍历根的左子树
    }
    TreeNode* convertBST(TreeNode* root) {
        traverse(root);
        return root;
    }
};