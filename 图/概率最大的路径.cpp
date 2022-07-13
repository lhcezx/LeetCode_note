// Dijkstra
class Solution {
public:
    vector<vector<pair<int, double>>> buildGraph(int n, vector<vector<int>>& edges, vector<double>& succProb) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int from = edges[i][0];
            int to = edges[i][1];
            double prob = succProb[i];
            graph[from].emplace_back(to, prob);             //  无向加权图
            graph[to].emplace_back(from, prob);
        }
        return graph;
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph = buildGraph(n, edges, succProb);                               //  构建无向加权图
        auto cmp = [&] (const auto& a, const auto& b) {return a.second < b.second;};                            //  最大堆，在堆顶是概率最大的路径
        priority_queue<pair<int, double>, vector<pair<int, double>>, decltype(cmp)> pq(cmp);                    //  从start到节点i的路径成功的概率，first保存节点，second保存概率
        vector<double> prob(n, 0.0);                                                                            //  记录到达每个节点的成功的最大概率
        pq.push({start, 1});
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int cur_node = top.first;
            double cur_prob = top.second;
            if (cur_node == end) return cur_prob;
            if (cur_prob < prob[cur_node]) continue;                                                     //  如果到cur_node这条路径的概率比之前保存的到这个节点的路径概率还小，则直接跳过
            for (auto neighbor: graph[cur_node]) {
                int next_node = neighbor.first;
                double next_prob = neighbor.second;
                if (cur_prob * next_prob > prob[next_node]) {
                    prob[next_node] = cur_prob * next_prob;
                    pq.push({next_node, cur_prob * next_prob});
                }
            }
        }
        return 0.0;
    }
};