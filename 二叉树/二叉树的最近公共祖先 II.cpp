/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool find_p = false, find_q = false;
public:
    TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        TreeNode* left = find(root->left, p, q);
        TreeNode* right = find(root->right, p, q);
        //  需要后序遍历判断root的值，因为我们需要遍历整个二叉树的每一个节点找pq是否存在，若不存在则返回Null，存在则找其公共子节点。前面的前序遍历无法遍历每个子节点，而是找到一个就会直接返回，这种情况对于一个节点存在，另一个不存在的情况结果会返回那个存在的节点，而答案应该是nullptr
        if (root == p) {
            find_p = true;
            return root;
        } else if (root == q) {
            find_q = true;
            return root;
        }
        if (left != nullptr && right != nullptr) return root;
        return left == nullptr? right: left;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = find(root, p, q);
        if (find_p && find_q) return res;
        return nullptr;
    }
};