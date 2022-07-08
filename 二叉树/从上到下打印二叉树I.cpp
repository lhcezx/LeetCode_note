class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        while (!q.empty()) {
            if (q.front()) {
                v.push_back(q.front()->val);
                if (q.front()->left) {
                    q.push(q.front()->left);
                }
                if (q.front()->right) {
                    q.push(q.front()->right);
                }
            }    
            q.pop();
        }
        return v;

    }
};