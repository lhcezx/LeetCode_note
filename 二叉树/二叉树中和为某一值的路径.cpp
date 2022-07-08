class Solution {
    vector<vector<int>> ans;
    vector<int> path;
public:
    void recur(TreeNode* root, int target) {
        if (!root) return;
        path.push_back(root->val);
        target -= root->val;
        if (target == 0 && !root->left && !root->right) {
            ans.push_back(path);
        }
        recur(root->left, target);
        recur(root->right, target);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        recur(root, target);
        return ans;
    }
};