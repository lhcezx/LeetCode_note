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
    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {     //  min和max为两个树节点，用于判断根节点是否大于整个左子树的节点，和根节点是否小于整个右子树的节点。而不是仅仅判断是否大于小于左子节点和右子节点
        if (root == nullptr) return true;
        if (min != nullptr && root->val <= min->val) return false;
        if (max != nullptr && root->val >= max->val) return false;
        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);             //  左子树的节点的值最小必须大于min的值，最大不能超过root的值; 右子树的节点最小不能小于root的值，最大不能大于max的值
    }

    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }
};