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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if (root == nullptr) return res;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            deque<int> dq;
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (level % 2 == 0) {                           //  偶数层从左向右入队，奇数层从右向左入队
                    dq.push_back(cur->val);
                } else {
                    dq.push_front(cur->val);
                }
                if (cur->left != nullptr) q.push(cur->left);  
                if (cur->right != nullptr) q.push(cur->right);
            }
            level++;
            res.push_back(vector<int> (dq.begin(), dq.end()));
        }
        return res;
    }
};