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
    unordered_map<TreeNode*, int> memo;
public:
    int rob(TreeNode* root) {
        if (root == nullptr) return 0;
        if (memo.count(root)) return memo[root];
        int do_it = root->val;                 
        //  做选择，抢当前root节点还是不抢
        //  如果我们偷了根节点，那么我们就不能偷左子节点和右子节点，查看左子节点是否为空，若不为空则偷其左子和右子节点
        if (root->left != nullptr) {
            TreeNode* ll = root->left->left;
            TreeNode* lr = root->left->right;
            do_it += rob(ll) + rob(lr);
        }
        if (root->right != nullptr) {
            TreeNode* rl = root->right->left;
            TreeNode* rr = root->right->right;
            do_it += rob(rl) + rob(rr);
        }  
        int not_do = rob(root->left) + rob(root->right);                //  如果不偷当前节点，则偷其左子节点和右子节点
        return memo[root] = max(do_it, not_do);
    }
};