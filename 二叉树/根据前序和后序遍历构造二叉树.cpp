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
    vector<int> preorder, postorder;
    unordered_map<int, int> postorder_idx;
public:
    TreeNode* build(int pre_left, int pre_right, int post_left, int post_right) {
        if (post_left > post_right) return nullptr;
        if (pre_left == pre_right) return new TreeNode(preorder[pre_left]); //  防止pre_left + 1越界
        int root_val = preorder[pre_left];                                  //  找到根节点的值
        int left_root_idx = postorder_idx[preorder[pre_left + 1]];          //  左子树的根节点在后序遍历中的下标
        int left_len = left_root_idx - post_left + 1;                       //  计算左子树长度
        TreeNode* root = new TreeNode(root_val);
        root->left = build(pre_left + 1, pre_left + left_len, post_left, left_root_idx);         //  递归的构建左子树
        root->right = build(pre_left + left_len + 1, pre_right, left_root_idx + 1, post_right - 1);          //  递归的构建右子树
        return root;                                                                               
    } 


    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        this->preorder = preorder;
        this->postorder = postorder;
        for (int i = 0; i < postorder.size(); i++) {
            postorder_idx[postorder[i]] = i;            //  记录后序遍历中每个元素的下标
        }
        return build(0, preorder.size() - 1, 0 , postorder.size() - 1);
    }
};