//  题目的思路是，在前序遍历中找到根节点root，然后根据根节点的值找到找到中序遍历中根节点的索引i，然后通过中序遍历子树的左边界left和right可以分别和i计算得到左子树长度和右子树长度(右子树长度不重要), 进而通过root+1在前序遍历中找到左子树的根节点和root+len_left_subtree+1找到前序遍历中右子树的根节点，并分别更新left和right。
//  对于左子树的子树的中序遍历左边界更新为left(不变), 右边界更新为i-1。右子树的子树的中序遍历左边界更新为i+1, 有边界更新为right不变。函数返回值为root节点，如此递归的建立root->left和root->right
//  函数中left和right的目的有两个: 1. 如果left > right则完成遍历，返回Nullptr。2. 根据left和right计算左子树长度从而推出右子树根节点在前序遍历中的位置。

class Solution {
    vector<int> preorder;
    unordered_map<int, int> hash_map;
public:
    // root是前序遍历中根节点的索引，left为中序遍历子树的左边界，right为中序遍历子树的有边界。
    TreeNode* recur(int root, int left, int right) {
        if (left > right) return nullptr;               // 如果子树的左边界比右边界大，则说明越过叶节点，直接返回
        TreeNode* node = new TreeNode(preorder[root]);  // 创建根节点并根据前序遍历中根节点的索引赋值
        int i = hash_map[preorder[root]];               // 找到根节点在中序遍历中的索引i
        int len_left_subtree = i - left;                // 计算左子树长度
        // 注意，recur的第一个参数为 “前序遍历” 的子树的根节点的索引，后两个参数为 “中序遍历” 的子树的左边界和有边界索引
        node->left = recur(root + 1, left, i - 1);      // 递归以root为根节点的左子树, root + 1代表左子树的根节点在前序遍历中的索引, left为root的左子树的子树的左边界,right为root的左子树的子树的右边界
        node->right = recur(root + len_left_subtree + 1, i + 1, right); // root+len_left_subtree+1为root的右子树在前序遍历中的根节点索引, i+1为右子树的子树的左边界, right为右边界
        return node;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        for (int i = 0; i < inorder.size(); i++) {
            hash_map[inorder[i]] = i;
        }
        return recur(0, 0, inorder.size() - 1);
    }
};