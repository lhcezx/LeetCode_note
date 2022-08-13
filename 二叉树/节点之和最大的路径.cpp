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

//  未优化版
//  这里单独用了一个traverse函数，遍历每一个节点并将其作为根节点，计算最大路径和
class Solution {
    int max_val = INT_MIN;
public:
    //  返回以root为根节点的最大左路径或右路径和
    int maxSum(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = max(0, maxSum(root->left));
        int right = max(0, maxSum(root->right));
        return max(left, right) + root->val;
    }

    void traverse(TreeNode* root) {
        if (root == nullptr) return;
        int left = max(maxSum(root->left), 0);
        int right = max(maxSum(root->right), 0);
        max_val = max(max_val, left + right + root->val);
        traverse(root->left);
        traverse(root->right);
    }
    //  返回以root为根节点的最大路径和
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return max_val;
    }
};


//  优化版
//  实际traverse可以省略掉，因为在递归计算左子树最大单边路径和右子树最大单边路径时，可以将其加和再加根节点就是以root节点为根节点的最大路径和，一次递归即可全部计算
class Solution {
    int max_val = INT_MIN;
public:
    //  返回以root为根节点的最大单边路径和
    int maxSum(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = max(0, maxSum(root->left));
        int right = max(0, maxSum(root->right));
        max_val = max(max_val, left + right + root->val);
        return max(left, right) + root->val;
    }


    //  返回以root为根节点的最大路径和
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return max_val;
    }
};