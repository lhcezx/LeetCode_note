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
    unordered_map<int, int> hash_map;           //  哈希表的键对应的是从root到当前node的路径和(前缀和)，值对应的是路径和出现的次数
    int res = 0;
    int target;                                 //  记录我们要找的路径和
public:
    void traverse(TreeNode* root, int pre_sum) {
        if (root == nullptr) return;
        pre_sum += root->val;
        if (hash_map.count(pre_sum - target)) res += hash_map[pre_sum - target];        //  如果当前路径和pre_sum减掉target的差在前缀和中存在，则证明存在子路径其和等于target。子路径和的个数为哈希表中存放的次数
        hash_map[pre_sum]++;
        traverse(root->left, pre_sum);
        traverse(root->right, pre_sum);
        hash_map[pre_sum]--;                                //  当我们离开这个节点的时候，需要删除这个节点对应的前缀和

    }
    int pathSum(TreeNode* root, int targetSum) {
        hash_map[0] = 1;                                    //  这里要让前缀和0等于1，也就是当路径和pre_sum == target的时候，pre_sum - target = 0，因此存在一条路径就是当前路径本身
        target = targetSum;
        traverse(root, 0);
        return res;
    }
};