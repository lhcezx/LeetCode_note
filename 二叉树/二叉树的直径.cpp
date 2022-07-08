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
    int max_diameter = 0;
public:
    int maxdepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int left_depth = maxdepth(root->left);
        int right_depth = maxdepth(root->right);
        max_diameter = max(left_depth + right_depth, max_diameter);         //  我们将max_diameter方在maxdepth函数的后序遍历的位置，因为在这种情况下我们是知道左子树和右子树的最大深度的
        return max(left_depth, right_depth) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxdepth(root);
        return max_diameter;
    }
};