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
class BSTIterator {
    stack<TreeNode*> s;       //  用栈模拟对BST的中序递归遍历
public:
    BSTIterator(TreeNode* root) {
        pushLeftBranche(root);
    }
    
    //  将从根节点的每一个元素压入栈，直到找到BST的最小节点也就是最左下的节点
    //  该函数的本质意义为找到以root作为根结点的二叉搜索树的底层最左边的值，即最小值
    void pushLeftBranche(TreeNode* root){
        while (root != nullptr) {       
            s.push(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode* tmp = s.top();
        s.pop();
        pushLeftBranche(tmp->right);
        return tmp->val;
    }
    
    bool hasNext() {
        if (!s.empty()) return true;
        return false;
    }

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */