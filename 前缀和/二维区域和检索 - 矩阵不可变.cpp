class NumMatrix {
    vector<vector<int>> pre_sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        pre_sum.resize(rows + 1, vector<int>(cols + 1));
        for (int i = 1; i <= rows; i++) {           //  由于递推公式用的是i-1, j-1作为索引，因此当i,j = 0的时候会报错，因此我们将前面的元素设置为0，matrix[0][0]的前缀和葱presum[1][1]开始
            for (int j = 1; j <= cols; j++) {
                pre_sum[i][j] = pre_sum[i-1][j] + pre_sum[i][j-1] - pre_sum[i-1][j-1] + matrix[i-1][j-1];   //  左上角的矩阵是没有前缀和的，不需要考虑
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pre_sum[row2 + 1][col2 + 1] - (pre_sum[row1][col2 + 1] + pre_sum[row2+1][col1] - pre_sum[row1][col1]);
    }
};


/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */