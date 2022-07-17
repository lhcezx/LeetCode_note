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

// DFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr) return minDepth(root->right) + 1;            //  若左子树为空，则需要计算root的右子树的最小深度 + root节点
        if (root->right == nullptr) return minDepth(root->left) + 1;            //  若右子树为空，则需要计算root左子树的最小深度 + root节点
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};


// BFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            depth++;
            for (int i = 0; i < sz; i++) {              //  遍历当前层的每一个节点
                TreeNode* front = q.front();
                q.pop();
                if (front->left != nullptr) q.push(front->left);
                if (front->right != nullptr) q.push(front->right);
                if (front->left == nullptr && front->right == nullptr) return depth;
            }
        }
        return depth;
    }
};