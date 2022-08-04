class Solution {
    unordered_map<int, int> hash_map;
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));                   //  dp[i][j]返回以i和j为序列中倒数两个数的斐波那契序列的最长长度，注意这里i > j, 如果不限制该条件会造成重复计算
        int res = 0;
        for (int i = 0; i < n; i++) hash_map[arr[i]] = i;               //  用哈希表保存每个元素的索引
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (!hash_map.count(arr[i] - arr[j])) dp[i][j] = 0;     //  若不存在arr[k] + arr[j] = arr[i]，则不构成斐波那契数列
                else {
                    int k = hash_map[arr[i] - arr[j]];
                    if (k >= j) continue;                               //  这里同样需要保证j > k
                    dp[i][j] = max(dp[j][k] + 1, 3);                    //  由于初始化dp[i][j]全部为0，因此dp[j][k]可能为0，但是数列长度最短不能短于3.
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};