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
    unordered_map<string, int> hash_map;          //  用于存放相同序列化的根节点出现的次数
    vector<TreeNode*> res;                        //  用于记录重复子树的根节点
public:
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#,";
        string left = serialize(root->left);
        string right = serialize(root->right);
        string tree = left + ',' + right + ',' + to_string(root->val);          //  序列化后的二叉树， 这里采用后序遍历写法，其实前中后序遍历都可以，只是为了通过序列化来表达一颗子树
        if (hash_map.count(tree)) {
            if (hash_map[tree] == 1) res.push_back(root);                       //  避免放入重复的根节点
        }
        hash_map[tree]++;
        return tree;         
    }


    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return res;
    }
};