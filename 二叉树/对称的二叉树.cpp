//  递归
class Solution {
public:
    //  函数返回以left为根节点的左子树和以right为根节点的右子树是否对称
    bool check(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;               //  若左右子树都是nullptr，代表检查到了叶节点，返回true;
        if (left == nullptr || right == nullptr) return false;              //  若左右节点其中一个非空另一个空，则必不对称
        //  当左右子节点的值相等，并且左子节点的左子树和右子节点的右子树对称，左子节点的右子树和右子节点的左子树对称时，那么左右子节点的子树对称1
        return left->val == right->val && check(left->left, right->right) && check(left->right, right->left);      
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};


//  迭代
class Solution {
public:
    bool check(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode* left = q.front();
            q.pop();
            TreeNode* right = q.front();
            q.pop();
            if (left == nullptr && right == nullptr) continue;
            if (left == nullptr || right == nullptr || (left->val != right->val)) return false;
            q.push(left->left);
            q.push(right->right); 
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root);
    }
};