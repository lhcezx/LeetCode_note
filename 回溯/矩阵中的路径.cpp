class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, vector<vector<bool>>& visited, int idx) {
        int m = board.size(), n = board[0].size();
        if (idx == word.size()) return true;
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) return false;
        visited[i][j] = true;
        bool res = false;
        if (board[i][j] == word[idx]) {
            res = dfs(board, word, i + 1, j, visited, idx + 1) || dfs(board, word, i - 1, j, visited, idx + 1) || dfs(board, word, i, j + 1, visited, idx + 1) || dfs(board, word, i, j - 1, visited, idx + 1);
        }
        visited[i][j] = false;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, visited, 0)) return true;
            }
        }
        return false;
    }
};