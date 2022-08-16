// 如果从左上开始搜索，无论向下还是向右都是增加，因此无法做出判断。 从右上角开始搜索的原因是: 向左移动可以让数字减少，向下移动可以让数字增加。
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int row = 0, col = cols - 1;                            //  从右上角开始搜索
        while (row < rows && col >= 0) {
            if (matrix[row][col] > target) col--;       
            else if (matrix[row][col] < target) row++;
            else return true;
        }
        return false;
    }
};