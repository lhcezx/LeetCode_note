class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (!root) {
            return res;
        }
        q.push(root);
        while (!q.empty()) {
            res.push_back(vector<int> ());
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                res.back().push_back(q.front()->val);
                if (q.front()->left) {q.push(q.front()->left);}
                if (q.front()->right) {q.push(q.front()->right);}
                q.pop();
            }
        }
        return res;
    }
};