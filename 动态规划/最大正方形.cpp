//  dp[i][j]表示以matrix[i][j]为右下角点的正方形的最大边长，dp[i][j]状态由min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])转移过来。假设以i,j为右下角的正方形最大边长为4，则以[i-1, j], [i, j-1], [i-1, j-1]为右下角的正方形最大边长都必须为3，如果其中一个的边长小于等于3，则dp[i][j]所保存的最大边长也会随之减小
class Solution {
public:
    int _min(int a, int b, int c) {
        return min(a, min(b, c));
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int max_side = -1;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int> (cols, 0));                //  dp[i][j] 返回以matrix[i][j]为右下角点的最大正方形边长
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else {
                    if (i == 0 || j == 0) dp[i][j] = 1;                     //  base case: 第一行和第一列的最大正方形面积是0或1
                    else dp[i][j] = _min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                }
                max_side = max(max_side, dp[i][j]);
            }
        }
        return max_side * max_side;
    }
};