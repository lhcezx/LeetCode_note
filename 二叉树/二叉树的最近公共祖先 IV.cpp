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
    
public:
    TreeNode* find(TreeNode* root, unordered_set<int>& hash_set) {
        if (root == nullptr) return nullptr;
        if (hash_set.count(root->val)) return root;         // root恰好是我们要找到的节点之一，直接返回
        TreeNode* left = find(root->left, hash_set);
        TreeNode* right = find(root->right, hash_set);
        if (left != nullptr && right != nullptr) return root;           //  如果左右传上来的节点都不为空，则root是某两个节点的公共祖先，然后root会继续向上传，可能会和其他的节点一起上传作为左右节点获得新的公共祖先
        return left == nullptr? right: left;                            //  当左子树收到的结果不为空，则上传左子树结果，否则上传右子树结果，右子树若也为空则直接上传空节点，若右子树不为空则上传右节点
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        unordered_set<int> hash_set;
        for (auto node: nodes) {
            hash_set.insert(node->val);
        }
        return find(root, hash_set);
    }
};