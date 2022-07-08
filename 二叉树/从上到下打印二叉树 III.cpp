class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        TreeNode* node;
        bool IsOrderLeft = true;
        if (!root) {
            return res;
        }
        q.push(root);

        while (!q.empty()) {
            deque<int> dq;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                // 这部分代码是为了将节点按照要求顺序存到双端队列中，如果对打印从左到右顺序没有要求则不需要这个双端队列
                if (IsOrderLeft) {
                    dq.push_back(q.front()->val);
                } else {
                    dq.push_front(q.front()->val);
                }
                //
                if (q.front()->left) {q.push(q.front()->left);}
                if (q.front()->right) {q.push(q.front()->right);}
                q.pop();
            }
            res.push_back(vector<int>(dq.begin(), dq.end()));
            IsOrderLeft = !IsOrderLeft;
        }
        return res;
    }
};