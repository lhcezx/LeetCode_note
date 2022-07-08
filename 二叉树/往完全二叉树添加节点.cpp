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
class CBTInserter {
    TreeNode* root;
    queue<TreeNode*> q;
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
    }
    
    int insert(int v) {
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            if (tmp->left != nullptr && tmp->right != nullptr) q.pop();
            else if (tmp->left == nullptr) {
                tmp->left = new TreeNode(v);
                return tmp->val;
            } else if (tmp->right == nullptr) {
                tmp->right = new TreeNode(v);
                return tmp->val;
            } 
            
            if (tmp->left != nullptr) q.push(tmp->left);
            if (tmp->right != nullptr) q.push(tmp->right);
        }
        return -1;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */