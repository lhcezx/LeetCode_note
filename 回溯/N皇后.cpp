class Solution {
    vector<vector<string>> res;
public:
    //  不需要检查row下面的行，因为还没放皇后，也不需要检查row这一行，因为我们只会放一个皇后
    bool isValid(vector<string>& board, int row, int col) {
        int n = board[row].length();
        for (int i = 0; i <= row; i++) {
            if (board[i][col] == 'Q') return false;                         //  检查同列的每一行是否已经存在皇后
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {     //  检查(row, col)的右上斜线路径上是否有皇后
            if (board[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {    //  检查(row, col)的左上斜线路径上是否有皇后
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }

    void backtrack(vector<string>& board, int row) {
        if (row >= board.size()) {
            res.push_back(board);
            return;
        }
        for (int j = 0; j < board.size(); j++) {
            if (!isValid(board, row, j)) continue;      //  如果位置不合法，直接跳过
            board[row][j] = 'Q';
            backtrack(board, row + 1);
            board[row][j] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }
};