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
    vector<TreeNode*> build (int low, int high) {
        vector<TreeNode*> res;
        if (low > high) {       //  如果区间为空，则返回空指针
            res.push_back(nullptr);
            return res;
        }
        if (low == high) {      //  如果区间为1，则返回当前节点
            res.push_back(new TreeNode(low));
            return res;
        } 
        for (int i = low; i <= high; i++) {
            vector<TreeNode*> left_list = build(low, i - 1);      //  分别建立左右子树的nodelist
            vector<TreeNode*> right_list = build(i + 1, high);
            for (auto left: left_list) {                          //  遍历左右子树的list
                for (auto right: right_list) {
                    TreeNode* root = new TreeNode(i);             //  构建根节点，其左子节点，右子节点
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }
};