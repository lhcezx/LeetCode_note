class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX / 2));             //  保存[i, j]位置到周围最近的0所需要的步数
        //  base case
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) dp[i][j] = 0;
            }
        }
        //  从左向右，从上到下，正向扩散计算每个dp[i][j]
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] == 0) continue;
                int top = i - 1 >= 0? dp[i - 1][j]: INT_MAX / 2;            //  找到上下左右格子中距离周围0距离最小的那个值，再算上[i, j]本身 + 1即可
                int bottom = i + 1 < n? dp[i + 1][j]: INT_MAX / 2;
                int left = j - 1 >= 0? dp[i][j - 1]: INT_MAX / 2;
                int right = j + 1 < m? dp[i][j + 1]: INT_MAX / 2;
                dp[i][j] = min(top, min(bottom, min(left, right))) + 1;
            }
        }
        //  从右向左，从下到上，反向扩散计算每个dp[i][j] (因为正向扩散中某些位置i,j因为缺乏对周围的信息，会无法得到正确的值)
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (dp[i][j] == 0) continue;
                int top = i - 1 >= 0? dp[i - 1][j]: INT_MAX;
                int bottom = i + 1 < n? dp[i + 1][j]: INT_MAX;
                int left = j - 1 >= 0? dp[i][j - 1]: INT_MAX;
                int right = j + 1 < m? dp[i][j + 1]: INT_MAX;
                dp[i][j] = min(top, min(bottom, min(left, right))) + 1;
            }
        }
        return dp;
    }
};