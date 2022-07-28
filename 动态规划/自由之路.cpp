class Solution {
    vector<vector<int>> memo;
    unordered_map<char, vector<int>> ring_idx;          //  记录ring轮盘的每一个字符对应的下标, 注意一个字符可能有多个下标对应
public:
    //  函数返回指针在i位置，输入key[j...]的最小操作数
    int dp(string& ring, string& key, int i, int j) {
        if (j == key.size()) return 0;
        int n = ring.size();
        if (memo[i][j] != INT_MAX) return memo[i][j];
        int res = INT_MAX;
        for (int idx: ring_idx[key[j]]) {                             //  做选择，选择key[j]字符在轮盘ring中对应的每一个索引
            int delta = abs(idx - i);                                 //  转动的步数
            int subProb = dp(ring, key, idx, j + 1);                  //  将ring从i转到idx找到key[j], 然后找下一个字符j + 1
            res = min(res, min(delta, n - delta) + subProb + 1);      //  delta和n - delta代表顺时针和逆时针转动，+1代表按下
        }
        return memo[i][j] = res;
    }

    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        memo.assign(n, vector<int> (m, INT_MAX));
        for (int i = 0; i < n; i++) {
            ring_idx[ring[i]].push_back(i);
        }
        return dp(ring, key, 0, 0);             //  返回初始i指针位置为0，输入key[0...]的最小操作数
    }
};