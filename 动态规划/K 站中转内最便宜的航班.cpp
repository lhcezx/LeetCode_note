//  DP
class Solution {
    vector<vector<int>> memo;
    vector<vector<pair<int, int>>> graph;
public:
    void buildGraph(vector<vector<int>>& flights, int n) {
        graph.assign(n, vector<pair<int, int>>());
        for (auto flight: flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            graph[from].emplace_back(to, price);
        }
    }

    //  函数返回从src到dst的最多经过K次中转的最便宜价格
    int dp(vector<vector<pair<int, int>>>& graph, int src, int dst, int k) {
        if (src == dst) return 0;                //  base case
        if (k == -1) return INT_MAX;             //  达到中转上限
        if (memo[src][k] != -1) return memo[src][k];
        int res = INT_MAX;
        for (auto neighbor: graph[src]) {
            int node = neighbor.first;
            int price = neighbor.second;
            int subProb = dp(graph, node, dst, k - 1);
            if (subProb == INT_MAX) continue;
            res = min(res, subProb + price); 
        }
        return memo[src][k] = res;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        buildGraph(flights, n);
        memo.assign(n, vector<int> (k + 1, -1));
        int res = dp(graph, src, dst, k);
        return res == INT_MAX ? -1 : res;
    }
};


// Dijkstra
class Solution {
    vector<vector<pair<int, int>>> graph;
public:
    void buildGraph(vector<vector<int>>& flights, int n) {
        graph.assign(n, vector<pair<int, int>>());
        for (auto flight: flights) {
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];
            graph[from].emplace_back(to, price);
        }
    }

    struct state {
        int id;
        int nodeFromStart;
        int costFromStart;
        state(int _id, int _nodeFromStart, int _costFromStart): id(_id), nodeFromStart(_nodeFromStart), costFromStart(_costFromStart) {}
    };

    //  函数返回从src到dst的最多经过K次中转的最便宜价格
    int Dijkstra(int src, int dst, int k) {
        int n = graph.size();
        vector<int> distTO(n, INT_MAX);
        vector<int> nodeNumTo(n, INT_MAX);
        auto cmp = [&] (const auto &a, const auto &b) {return a.costFromStart > b.costFromStart;};
        priority_queue<state, vector<state>, decltype(cmp)> pq(cmp);
        distTO[src] = 0;                //  base case
        nodeNumTo[src] = 0;             //  base case
        pq.emplace(state(src, 0, 0));

        while (!pq.empty()) {
            state cur = pq.top();
            pq.pop();
            int id = cur.id;
            int nodeFromStart = cur.nodeFromStart;
            int costFromStart = cur.costFromStart;
            if (id == dst) return costFromStart;            
            if (nodeFromStart == k) continue;              //  中转次数耗尽
            for (auto neighbor: graph[id]) {
                int to = neighbor.first;
                int price = neighbor.second;
                if (distTO[to] > costFromStart + price) {
                    distTO[to] = costFromStart + price;
                    nodeNumTo[to] = nodeFromStart + 1;
                }
                //  如果费用比前面保存的更高且需要中转的节点更多，直接跳过
                if (distTO[to] < costFromStart + price && nodeNumTo[to] < nodeFromStart + 1) continue;
                pq.push(state(to, nodeFromStart + 1, costFromStart + price));
            }
        }
        return -1;
    }



    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        buildGraph(flights, n);
        return Dijkstra(src, dst, k + 1);
    }
};