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

//  在根节点计算时时间复杂度为O(logn) (因为两次while)，然后进入递归分别进入左子树和右子树，两个子树其中一个必然是满二叉树，因此其中一个递归只会执行一次，时间复杂度为O(logn), 另一棵子树不是满二叉树，因此需要根据普通二叉树计算节点总数的方式计算其节点个数。该递归需要遍历该子树的所有节点，递归次数为O(N/2)，递归函数复杂度为O（logn)
//  因此总时间复杂度为O(logn)(根节点) + O(logn) (满二叉树子树) + O(logn * n/2) (非满二叉树的子树).
class Solution {
public:
    int countNodes(TreeNode* root) {
        TreeNode* left_depth = root, *right_depth = root;
        int hl = 0, hr = 0;
        while (left_depth != nullptr) {
            hl++;
            left_depth = left_depth->left;
        }

        while (right_depth != nullptr) {
            hr++;
            right_depth = right_depth->right;
        }   
        if (hl == hr) return (int)pow(2, hl) - 1;       //  如果左右深度相等，那么为满二叉树，计算节点公式为2^h - 1
        else return 1 + countNodes(root->left) + countNodes(root->right);       //  如果左右深度不相等。则依照计算普通二叉树节点数目的方式计算节点数量
    }
};