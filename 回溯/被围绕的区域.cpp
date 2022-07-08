class Solution {
    int rows, cols;
public:
    void dfs(vector<vector<char>>& board, int i, int j) {                       //  遍历位置[i,j]和它上下左右四个方向，找到和它相邻的所有的O并且标记为A
        if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != 'O') return;
        board[i][j] = 'A';
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++) {        //  遍历第一列和最后一列
            dfs(board, i, 0);
            dfs(board, i, cols - 1);
        }
        for (int j = 1; j < cols - 1; j++) {    //  遍历第一行和最后一行, 由于第一个行和最后一行的第一个和最后一个元素已经在遍历列的时候遍历到，因此从1开始到m-2
            dfs(board, 0, j);
            dfs(board, rows - 1, j);
        }


        //  遍历每个位置，若为A则替换为O，若为O则替换为X
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};



