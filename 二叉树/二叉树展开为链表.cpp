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
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        flatten(root->left);            //  分治思想，首先拉平左子树
        flatten(root->right);           //  然后拉平右子树

        // 后序遍历位置
        TreeNode* left = root->left;
        TreeNode* right= root->right;
        root->left = nullptr;
        root->right = left;
        TreeNode* p = root;
        while (p->right != nullptr) {       //  找到接到右边的左子树的尾节点，然后将该尾节点和右子树相接
            p = p->right;
        } 
        p->right = right;
    }
};