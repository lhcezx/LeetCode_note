class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> neignbors = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {3, 1, 5}, {2, 4}};     //  邻接表
        unordered_set<string> visited;                                                              //  判断是否走过
        string s_board = "";
        int step = 0;
        for (int i = 0; i < 2; i++) {                                                               //  二维映射到一维string
            for (int j = 0; j < 3; j++) {
                s_board.append(to_string(board[i][j]));
            }
        }
        queue<string> q;
        visited.insert(s_board);
        q.emplace(s_board);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front();
                q.pop();
                if (cur == "123450") return step;
                int x = cur.find('0');
                for (int neignbor: neignbors[x]) {
                    swap(cur[neignbor], cur[x]);            //  0和邻居位置上的char交换
                    if (!visited.count(cur)) {
                        q.emplace(cur);
                        visited.insert(cur);
                    }
                    swap(cur[neignbor], cur[x]);            //  换回来
                }
            }
            step++;
        }
        return -1;
    }
};