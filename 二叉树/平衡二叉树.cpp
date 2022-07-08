// 方法1. dfs函数通过后续遍历递归计算出root节点的左右子树的最大深度，如果两者差大于1则false.
// 然后递归的对每一个节点的左右子树都计算最大深度，若最终root == null则证明遍历完毕

class Solution {
public:
    int dfs(TreeNode* root) {
        if (!root) return 0;
        return max(dfs(root->left), dfs(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return abs(dfs(root->left) - dfs(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right) ; // 如果根结点的左子树和右子树的深度之差小于等于1 且 根节点的左子节点构成的子树也满足这个性质 且 根节点的右子节点构成的子树也满足这个性质
    }
};