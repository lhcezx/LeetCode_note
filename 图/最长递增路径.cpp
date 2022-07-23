//  记忆化DFS
class Solution {
    vector<vector<int>> memo;
public:
    int _max(int t, int b, int l, int r) {
        return max(t, max(b, max(l, r)));
    }
    int dfs(vector<vector<int>>& matrix, int i, int j, int rows, int cols) {
        if (i >= rows || i < 0 || j >= cols || j < 0) return 0;
        if (memo[i][j]) return memo[i][j];                              //  如果某个位置已经被遍历过，则该位置一定遍历其周边位置并计算其最大递增路径了，因此直接返回
        memo[i][j]++;                                                   //  每个位置的最短递增路径为自身
        int top = (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j])? dfs(matrix, i - 1, j, rows, cols): 0;
        int bot = (i + 1 < rows && matrix[i + 1][j] > matrix[i][j])? dfs(matrix, i + 1, j, rows, cols): 0;
        int left = (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j])? dfs(matrix, i, j - 1, rows, cols): 0;
        int right = (j + 1 < cols && matrix[i][j + 1] > matrix[i][j])? dfs(matrix, i, j + 1, rows, cols): 0;
        return memo[i][j] = _max(top, bot, left, right) + 1;
    }


    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        int rows = matrix.size(), cols = matrix[0].size();
        memo.assign(rows, vector<int> (cols, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res = max(res, dfs(matrix, i, j, rows, cols));          //  遍历每一个位置，记录最大的递增路径
            }
        }
        return res;
    }
};