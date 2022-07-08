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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if (root == nullptr) return res;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            int max_val = INT_MIN;
            for (int i = 0; i < sz; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                max_val = max(max_val, tmp->val);
                if (tmp->left != nullptr) q.push(tmp->left);
                if (tmp->right != nullptr) q.push(tmp->right);
            }
            res.push_back(max_val);
        }
        return res;
    }
};