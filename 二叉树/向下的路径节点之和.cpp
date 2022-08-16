class Solution {
    unordered_map<long, int> hash_map;              //  哈希表的键对应的是从root到当前node的路径和(前缀和)，值对应的是路径和出现的次数
    int res = 0;
public:
    void traverse(TreeNode* root, long sum, const int targetSum) {
        if (root == nullptr) return;
        sum += root->val;
        if (hash_map.count(sum - targetSum)) {
            res += hash_map[sum - targetSum];       //  如果当前路径和pre_sum减掉target的差在前缀和中存在，则证明存在子路径其和等于target。子路径和的个数为哈希表中存放的次数
        } 
        hash_map[sum]++;
        traverse(root->left, sum, targetSum);
        traverse(root->right, sum, targetSum);
        hash_map[sum]--;                            //  由于规定路径必须是向下的，所以当我们离开这个节点的时候，需要删除这个节点对应的前缀和
    }

    int pathSum(TreeNode* root, int targetSum) {
        hash_map[0] = 1;                            //  这里要让前缀和0等于1，也就是当路径和pre_sum == target的时候，pre_sum - target = 0，因此存在一条路径就是当前路径本身
        traverse(root, 0, targetSum);
        return res;
    }
};