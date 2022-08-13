class Solution {
    vector<vector<bool>> onPath;
public:
    bool backtrack(vector<vector<char>>& board, string& word, int i, int j, int k) {
        int rows = board.size(), cols = board[0].size();
        if (k >= word.size()) return true;
        if (i >= rows || j >= cols || i < 0 || j < 0 || onPath[i][j]) return false;         //  如果[i,j]单元格越界或者正在遍历，返回false
        if (board[i][j] != word[k]) return false;
        if (board[i][j] == word[k]) {
            onPath[i][j] = true;
            if (backtrack(board, word, i + 1, j, k + 1) || backtrack(board, word, i, j + 1, k + 1) || backtrack(board, word, i - 1, j, k + 1) || backtrack(board, word, i, j - 1, k + 1)) return true;
            onPath[i][j] = false;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        onPath.assign(rows, vector<bool> (cols, false));
        //  将每个格子作为起点寻找word
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (backtrack(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};