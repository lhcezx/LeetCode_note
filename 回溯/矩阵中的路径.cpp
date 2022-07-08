class Solution {
public:
    int rows, columes;
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size(), columes = board[0].size();
        int row, colume, counter;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columes; ++j) {
                if (board[i][j] == word[0]) {
                    row = i;
                    colume = j;
                    counter = 0;
                    if (research(board, row, colume, counter, word)) {return true;}
                }
            }
        }
        return false;
    }
    

    bool research(vector<vector<char>>& board, int i, int j, int counter, string word) {
        bool res;
        if (i >= rows || i < 0 || j >= columes || j < 0 || board[i][j] != word[counter]) return false;
        if (counter == word.length() || word.length() == 1) return true;
        board[i][j] = '\0';
        res = research(board, i+1, j, counter+1, word) || research(board, i-1, j, counter+1, word) || research(board, i, j+1, counter+1, word) || research(board, i, j-1, counter+1, word);
        board[i][j] = word[counter];
        return res;
    }
};