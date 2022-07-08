class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0){
            return false;
        }
        int rows = matrix.size();
        int columes = matrix[0].size();
        // begin from up right 
        int row = 0, colume = columes - 1;
        while (row < rows && colume >= 0) {
            if (matrix[row][colume] > target){
                colume--;
            } else if (matrix[row][colume] < target){
                row++;
            } else {
                return true;
            }
        }
        return false;

    }
};