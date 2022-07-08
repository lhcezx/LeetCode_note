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
    vector<int> preorder;
    vector<int> inorder;
    unordered_map<int, int> inorder_idx;                                // 用于记录每个元素在中序遍历中出现的下标位置
public: 
    TreeNode* build(int pre_left, int pre_right, int in_left, int in_right) {       //  前序遍历左右边界，中序遍历左右边界
        if (in_left > in_right) return nullptr;
        int root_val = preorder[pre_left];
        int root_idx = inorder_idx[root_val];                   //  找到根结点在中序遍历中的下标
        TreeNode* root = new TreeNode(root_val);
        int left_len = root_idx - in_left;                      //  左子树的长度
        root->left = build(pre_left + 1, pre_left + left_len, in_left, root_idx - 1);
        root->right = build(pre_left + left_len + 1, pre_right, root_idx + 1, in_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
                
        for (int i = 0; i < inorder.size(); i++) {
            inorder_idx[inorder[i]] = i;
        }
        return build(0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};