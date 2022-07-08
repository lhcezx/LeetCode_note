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
    vector<int> res;
public:
    void traverse(TreeNode* root) {         // 中序遍历，将结果保存在vector中
        if (root == nullptr) return;
        traverse(root->left);
        res.push_back(root->val);
        traverse(root->right);
    }

    bool findTarget(TreeNode* root, int k) {        
        traverse(root);
        int i = 0, j = res.size() - 1;
        while (i < j) {             //  双指针逐步逼近k值
            if (res[i] + res[j] > k) j--;
            else if (res[i] + res[j] < k) i++;
            else return true;
        }
        return false;
    }
};