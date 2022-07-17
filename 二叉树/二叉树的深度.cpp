// 前序遍历
class Solution {
    int res = 0;
public:
    void dfs(TreeNode* root, int depth) {
        if (!root) return;
        depth++;
        res = max(res, depth);
        dfs(root->left, depth);
        dfs(root->right, depth);
    }

    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        dfs(root, 0);
        return res;
    }
};

// 后序遍历
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        
    }
};

//  BFS

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            while (sz > 0) {
                TreeNode* tmp = q.front(); q.pop();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
                sz -= 1;
            }
            res += 1;
        }
        return res;

    }
};