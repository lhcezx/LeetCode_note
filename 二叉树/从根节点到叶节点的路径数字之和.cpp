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
    vector<int>res;
    
public:
    TreeNode* traverse(TreeNode* root, int sum) {
        if (root == nullptr) return nullptr;
        sum = sum * 10 + root->val;
        root->left = traverse(root->left, sum);
        root->right = traverse(root->right, sum);
        if (root->left == nullptr && root->right == nullptr) res.push_back(sum);
        return root;
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        root = traverse(root, sum);
        sum = accumulate(res.begin(), res.end(), 0);
        return sum;
    }
};