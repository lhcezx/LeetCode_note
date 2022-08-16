//  假如dp[i][j] == 4, 那么代表以[i, j]为右下角的正方形的最大边长为4，那么它的子正方形的边长可以是1, 2, 3和它本身4，也就是四个正方形。所以dp[i][j]保存的既是以[i, j]为右下角的正方形1的最大边长，也是以[i, j]为右下角的正方形的数量
class Solution {
public:
    int _min(int a, int b, int c) {
        return min(a, min(b, c));
    }

    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int counter = 0;
        vector<vector<int>> dp(rows, vector<int> (cols, 0));        //  dp[i][j]返回以[i, j]为右下角的正方形的个数，同时也是以[i, j]为右下角的正方形的最大边长
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = _min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                    }
                }
                counter += dp[i][j];
            }   
        }
        return counter;
    }
};