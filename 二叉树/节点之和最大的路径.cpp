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
    int max_sum = INT_MIN;
public:
    int maxGain(TreeNode* root) {
        if (root == nullptr) return 0;
        //  判断每一个节点的左子树和右子树的路径和是否大于0，在叶节点的时候就是判断左子节点和右子节点是否大于0，不大于0的话则不添加到路径和。
        int left = max(0, maxGain(root->left));     
        int right = max(0, maxGain(root->right));
        max_sum =  max(max_sum, root->val + left + right);      // 这里的max更新的是以当前root为根节点时，左右子树加当前根节点的值的最大路径和
        //  这里需要注意的是，返回的是子树的贡献量，不能返回max_sum, 因为max_sum返回的是以root为根结点，左右子树加根节点的最大路径和，而返回的贡献量是当前root作为子树对其上层递归中的root的贡献量，因此只能选择左子树或右子树，否则无法和上层递归的根节点构成路径
        return root->val + max(left, right);   

    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return max_sum;
        
    }
};