class Solution {
public:
    bool recur(vector<int>& postorder, int left, int right) {
        if (left >= right) return true;
        int i = left;
        int root = postorder[right];            //  找到根节点的位置，即postorder的最后一个值
        while (postorder[i] < root) i++;        //  从左向右找第一个比根节点值大的节点索引，即为根节点的右子树的叶子节点
        int right_subtree = i;                  //  找到右子树的叶子节点
        while (postorder[i] > root) i++;        //  遍历右子树，如果右子树的每一个值都比根节点大，则满足二叉搜索树条件
        return i == right && recur(postorder, left, right_subtree - 1) && recur(postorder, right_subtree, right - 1);

    }
    bool verifyPostorder(vector<int>& postorder) {
        return recur(postorder, 0, postorder.size() - 1);
    }
};