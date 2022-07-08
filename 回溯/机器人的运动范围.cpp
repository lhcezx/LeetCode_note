// dfs

class Solution {
public:
    int rows, cols;
    int val(int a) {
        int res = 0;
        while (a) {
            res += a%10;
            a /= 10;
        }
        return res;
    }

    int dfs (int i, int j, int k, vector<vector<bool>> &visited) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j]) return 0;
        if (val(i) + val(j) > k) return 0;
        visited[i][j] = true;
        return 1 + dfs(i + 1, j, k, visited) + dfs(i, j + 1, k, visited);
    }

    int movingCount(int m, int n, int k) {
        int row = 0, col = 0; 
        rows = m, cols = n;
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        return dfs(row, col, k, visited);
        
    }
};


// bfs

class Solution {
public:
    int val(int a) {
        int res = 0;
        while (a) {
            res += a%10;
            a /= 10;
        }
        return res;
    }

    int movingCount(int m, int n, int k) {
        int i = 0, j = 0, res = 0; 
        queue<vector<int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        q.push({0, 0});
        while (!q.empty()) {
            i = q.front()[0], j = q.front()[1];
            q.pop();
            if (i >= m || j >= n || val(i) + val(j) > k || visited[i][j]) continue;
            visited[i][j] = true;
            res++;
            q.push({i+1, j});
            q.push({i, j+1});
            
        }
        return res;
    }
};
