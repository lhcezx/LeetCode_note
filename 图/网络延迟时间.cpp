class Solution {
public:
    vector<vector<pair<int, int>>> buildGraph(vector<vector<int>>& times, int n) {      // 构建邻接表
        vector<vector<pair<int, int>>> graph(n);
        for (auto& time: times) {
            int from = time[0] - 1;                                                     //  因为时间是从1到n, 而我们希望从0到n-1
            int to = time[1] - 1;
            int weight = time[2];
            graph[from].emplace_back(to, weight);                                       // first代表到哪个节点，second代表这条边的权重
        }
        return graph;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> distTo(n, INT_MAX);                                                 //  记录从start开始到某个节点的最小距离，类似dp的备忘录
        auto cmp = [&](const auto &a, const auto &b) {return a.second > b.second;};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);//  pair中first代表当前节点id, second代表distFromStart从起始节点到当前节点的路径和, 将路径和较小的排在前面, 贪心策略尽量从最小的路径中继续往前走直到终点       
        vector<vector<pair<int, int>>> graph = buildGraph(times, n);                    //  构建邻接表


        // dijkstra算法
        distTo[k - 1] = 0;                                                              //  起始节点到起始节点的距离为0，用于初始化
        heap.push({k - 1, 0});                                   
        while (!heap.empty()) {
            auto top = heap.top();                                                     //  取出从start开始到现在这层的最短路径
            heap.pop();
            int cur_id = top.first;
            int cur_weight = top.second;
            if (distTo[cur_id] < cur_weight) continue;                                  //  如果已经存在一条路径比当前的路径更短，则跳过当前路径
            for (auto neighbor: graph[cur_id]) {
                int weight = cur_weight + neighbor.second;                          //  起点到cur_id的路径和加上cur_id到邻居的和
                if (distTo[neighbor.first] > weight) {                                  //  如果备忘录保存的到edge.to节点的路径长度小于从start到top再到edge.to节点的路径，那么跳过
                    distTo[neighbor.first] = weight;
                    heap.push({neighbor.first, weight});
                }                         

            }
        }
        int res = 0;
        for (int i = 0; i < distTo.size(); i++) {
            if (distTo[i] == INT_MAX) return -1;
            res = max(res, distTo[i]);
        }
        return res;
    }
};

