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
    int res;
    int n = 0;          //  记录中序遍历到的第几个节点
public:
    void traverse(TreeNode* root, int k) {
        if (root == nullptr) return;
        traverse(root->left, k);
        n++;
        if (n == k) res = root->val;
        traverse(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        traverse(root, k);
        return res;
    }
};