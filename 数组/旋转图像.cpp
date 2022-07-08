class Solution {
public:
    void reverse(vector<int>& rows) {
        int i = 0, j = rows.size() - 1;
        while (i < j) {
            int tmp = rows[i];
            rows[i] = rows[j];
            rows[j] = tmp;
            i++;
            j--;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        //  以从左上角到右下角作为对角线将矩阵镜像反转
        for (int i = 0; i < rows; i++) {
            for (int j = i; j < cols; j++) {        
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        //  再将矩阵每行的元素reverse, 达到顺时针旋转90度的效果
        for (int i = 0; i < rows; i++) {
            reverse(matrix[i]);
        }
    }
};