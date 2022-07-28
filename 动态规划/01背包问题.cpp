# include<bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> memo; 
public:
    //  返回从[1, i]个物品中，装到容量为size的背包所能的得到的最大价值
    int dp(vector<pair<int, int>>& goods, int i, int size) {
        if (size == 0) return 0;
        if (i == -1) return 0;
        if (memo[i][size] != -1) return memo[i][size];
        if (goods[i].first > size) {
            return memo[i][size] = dp(goods, i - 1, size);
        } else {
            return memo[i][size] = max(dp(goods, i - 1, size), dp(goods, i - 1, size - goods[i].first) + goods[i].second); 
        }
        
    }
    
    int maxValue(vector<pair<int, int>>& goods, int size) {
        int n = goods.size();
        memo.assign(n, vector<int>(size + 1, -1));
        return dp(goods, n - 1, size);
    }
};


int main() {
    vector<pair<int, int>> goods;
    int N, V;
    int v_i, w_i; 
    cin >> N >> V;
    for (int i = 0; i < N; i++) {
        cin >> v_i >> w_i;
        goods.emplace_back(v_i, w_i);
    }
    Solution* s = new Solution();
    cout << s->maxValue(goods, V) << endl;
    return 0;
}