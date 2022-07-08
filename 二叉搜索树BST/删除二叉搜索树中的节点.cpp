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
    TreeNode* getMin_right_tree(TreeNode* root) {                          //  右子树最左下的节点就是右子树最小的节点
        while (root->left != nullptr) root = root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val > key) root->left = deleteNode(root->left, key); 
        else if (root->val < key) root->right = deleteNode(root->right, key);
        else {  
            // if (root->left == nullptr && root->right == nullptr) return nullptr;    如果要删除的节点的左右子节点均为空，则可以直接删除，这步可以被下面两行包含在内
            if (root->left == nullptr) return root->right;                     //  如果要删除的节点的左节点为空，则将右节点接到原来的要删除的节点的位置上
            if (root->right == nullptr) return root->left;
            if (root->left != nullptr && root->right != nullptr) {            //  如果左右子节点均不为空，则需要找到右子树最小的节点或者左子树最大的节点代替到要删除节点的位置上，这样才能保证BST的性质
                TreeNode* min_right = getMin_right_tree(root->right);         //  找到右子树最小的节点，用来代替当前要删除的节点
                root->right = deleteNode(root->right, min_right->val);        //  由于已经找到右子树最小的替代节点，因此我们需要将root节点和min_node替换位置，做法是首先将root右子树中存在的min_node删除
                min_right->left = root->left;                                 //  然后将root的左子树接到Min_node上
                min_right->right = root->right;                               //  将已经删除minnode的root的右子树接到min_node上
                root = min_right;                                             //  最后让root = min_node
                
            }
        }
        return root;
    }
};