class Solution {
    vector<vector<int>> dp_table;                       //  记录在每一个位置[i, j]的下降最小路径和
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        dp_table.resize(n, vector<int> (n, INT_MAX));
        for (int i = 0; i < n; i++) {                   //  base case
            dp_table[0][i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int left = j - 1 >= 0? dp_table[i - 1][j - 1]: INT_MAX;
                int mid = dp_table[i - 1][j];
                int right = j + 1 < n? dp_table[i - 1][j + 1]: INT_MAX;
                dp_table[i][j] = min(left, min(mid, right)) + matrix[i][j];
            }
        }
        int res = INT_MAX;
        for (int j = 0; j < n; j++) {
            res = min(res, dp_table[n - 1][j]);
        }
        return res;
    }
};