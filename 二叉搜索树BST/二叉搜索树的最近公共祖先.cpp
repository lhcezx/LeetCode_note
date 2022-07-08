/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* find(TreeNode* root, int min, int max) {
        if (root == nullptr) return nullptr;
        if (root->val < min) return find(root->right, min, max);        //  当根节点比两个节点值都小，那么需要遍历右子树
        else if (root->val > max) return find(root->left, min, max);    //  当根节点比两个节点值都大，那么需要遍历左子树
        else return root;                                               //  当根节点的值  min <= val <= max 的时候，说明要么根节点是两个节点其中之一(相等的情况) 要么两个节点分别在根节点的左子树和右子树中，那么这个节点就是他们的最近公共祖先
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int val1 = min(p->val, q->val);
        int val2 = max(p->val, q->val);
        return find(root, val1, val2);
    }
};