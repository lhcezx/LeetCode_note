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
public:
    TreeNode* getMin(TreeNode* root) {          // 如果root为nullptr的时候返回nullptr, 否则会遍历以root为根的子树并且找到底层的最左子节点
        while (root != nullptr && root->left != nullptr) root = root->left; 
        return root;
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == nullptr) return nullptr;
        TreeNode* successor = nullptr;
        if (root->val > p->val) {             //  说明p节点在root节点的左子树
            successor = inorderSuccessor(root->left, p);
            if (successor == nullptr) return root;          //  successor返回nullptr代表p节点的右子树不存在，因为getMin函数结束后不再递归而是直接返回获得的右子树的值给上一层递归，所以p节点为root的左子节点，此时直接返回root节点作为p节点的中序后继节点
        } else if (root->val < p->val) {
            successor = inorderSuccessor(root->right, p);   //  如果p是root的右子节点，假如返回的getMin为nullptr，代表p节点的右子树不存在，这种情况下p节点不存在中续后继节点，因此递归的接收nullptr后返回nullptr
        } else {
            successor = getMin(root->right);  //  找到了p节点，此时寻找它的右子树中的最左节点
        }

        return successor;
    }
};