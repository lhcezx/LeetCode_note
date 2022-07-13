class Solution {
public:
    struct state{
        int x;
        int y;
        int effortFromStart;                    //  记录从起始位置到当前x, y的effort最大值
        state(int _x, int _y, int _effortFromStart): x(_x), y(_y), effortFromStart(_effortFromStart) {}
    };

    vector<pair<int, int>> neignbor(vector<vector<int>>& heights, int x, int y) {       //  找到x, y相邻的节点
        vector<pair<int, int>> res;
        int n = heights.size();
        int m = heights[0].size();
        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        for (auto dir: dirs) {
            int next_x = x + dir.first;
            int next_y = y + dir.second;
            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;
            res.emplace_back(next_x, next_y);
        }
        return res;

    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> effortTo(n, vector<int>(m, INT_MAX));                                           //  记录从start到每一个位置的effort最大值
        auto cmp = [&] (const auto& a, const auto& b) {return a.effortFromStart > b.effortFromStart;};      //  选择effort最小的那条路径
        priority_queue<state, vector<state>, decltype(cmp)> heap(cmp);
        effortTo[0][0] = 0;                                                                                 //  其实位置(0, 0)的effort为0
        heap.push(state(0, 0, 0));
        while (!heap.empty()) {
            auto top = heap.top();
            heap.pop();
            int cur_x = top.x;
            int cur_y = top.y;
            int cur_effort = top.effortFromStart;
            if (cur_x == n - 1 && cur_y == m - 1) return cur_effort;
            if (cur_effort > effortTo[cur_x][cur_y]) continue;
            for (auto next: neignbor(heights, cur_x, cur_y)) {
                int next_x = next.first;
                int next_y = next.second;
                int effort_neignbor = max(cur_effort, abs(heights[next_x][next_y] - heights[cur_x][cur_y]));        //  (next_x, next_y)的effort值为 (cur_x, cur_y)的effort值和(cur_x, cur_y)与(next_x, next_y)的高度差之间更大的那个
                if (effort_neignbor < effortTo[next_x][next_y]) {
                    effortTo[next_x][next_y] = effort_neignbor;
                    heap.push(state(next_x, next_y, effort_neignbor));
                }
            }
        }
        return -1;
    }
};