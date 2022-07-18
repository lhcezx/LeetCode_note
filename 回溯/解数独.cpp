class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char k) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == k) return false;                   //  检查我们当前的这行有没有k
            if (board[i][col] == k) return false;                   //  检查我们当前的这列有没有k
            if (board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == k) return false;      //  检查对应的3x3方格内有没有相同的数字, [(row / 3) * 3, (col / 3) * 3]得到的是我们当前对应的3x3方格左上角格子坐标, i从0到2时, 行左边不变 (i / 3)，检索三列(i % 3); [3, 5]时检索3x3中第二行的每一列，[6,8]检索第三行的每一列
        }
        return true;
    }

    bool backtrack(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return backtrack(board, i + 1, 0);              //  当遍历完一行，则进入下一行
        if (board[i][j] != '.') return backtrack(board, i, j + 1);  //  若当前位置有数字，则无需穷举
        //  穷举部分
        for (char k = '1'; k <= '9'; k++) {                         //  每个[i, j]位置都有9种可能
            if (isValid(board, i, j, k)) {
                board[i][j] = k;
                if (backtrack(board, i, j + 1)) return true;
                board[i][j] = '.';
            } else continue;
        }
        return false;                                               //  9个数字都不能放，则返回false
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
};