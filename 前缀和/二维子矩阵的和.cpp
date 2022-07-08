class NumMatrix {
    vector<vector<int>> m;
    vector<vector<int>> pre_sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix;
        for (int i = 0; i < m.size(); i++) {
            int sum = 0;
            vector<int> tmp;
            for (int j = 0; j < m[0].size(); j++) {
                sum += m[i][j];
                tmp.push_back(sum);
            }
            pre_sum.push_back(tmp);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            sum += pre_sum[i][col2] - pre_sum[i][col1] + m[i][col1];   // 之所以不用pre[i][col2] - pre[i][col-1]是为了避免col1 = 0的情况
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */