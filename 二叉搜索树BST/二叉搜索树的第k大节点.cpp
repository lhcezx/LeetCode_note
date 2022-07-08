class Solution {
    int val;
public:
    void dfs(TreeNode* root, int& k) {
        if (!root) return;
        if(k) dfs(root->right, k);
        k--;
        if (k == 0) val = root->val;
        if(k) dfs(root->left, k);

    }

    int kthLargest(TreeNode* root, int k) {
        dfs(root, k);
        return val;
    }
};