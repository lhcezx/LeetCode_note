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
    unordered_map<int, int> inorder_idx;
    vector<int> inorder;
    vector<int> postorder;
public:
    TreeNode* build(int in_left, int in_right, int po_left, int po_right) {
        if (in_left > in_right) return nullptr;
        int root_val = postorder[po_right];
        int root_idx = inorder_idx[root_val];           //  找到根节点在中序遍历中的位置
        TreeNode* root = new TreeNode(root_val);
        int left_len = root_idx - in_left;
        root->left = build(in_left, root_idx - 1, po_left, po_left + left_len - 1);
        root->right = build(root_idx + 1, in_right, po_left + left_len, po_right - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        for (int i = 0; i < inorder.size(); i++) {
            inorder_idx[inorder[i]] = i;
        }
        return build(0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};