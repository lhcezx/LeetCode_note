//  双向有权图，BFS。将每个字符串变量映射成Id用来构成节点，用除法计算结果values代表两个节点的边的权重，每次计算请求queries[0]就是起点，quieries[1]是终点，计算之间的路径权重乘积

class Solution {
    vector<vector<pair<int, double>>> graph;
    unordered_map<string, int> var_Id;
    vector<bool> visited;
    int numNodes = 0;
public:
    void buildGraph(vector<vector<string>>& equations, vector<double>& values) {
        //  给每个变量创建哈希映射
        for (auto& equation: equations) {                               
            string from = equation[0];
            string to = equation[1];
            if (!var_Id.count(from)) var_Id[from] = numNodes++;
            if (!var_Id.count(to)) var_Id[to] = numNodes++;
        }
        graph.assign(numNodes, vector<pair<int, double>>());       
        for (int i = 0; i < equations.size(); i++) {
            int from_id = var_Id[equations[i][0]];
            int to_id = var_Id[equations[i][1]];
            double val = values[i];
            graph[from_id].emplace_back(to_id, val);
            graph[to_id].emplace_back(from_id, 1 / val);
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        buildGraph(equations, values);
        for (auto querie: queries) {
            visited.assign(numNodes, false);                              //  每次有新的计算请求，需要将visited全部重置为false
            if (!var_Id.count(querie[0]) || !var_Id.count(querie[1])) {
                res.push_back(-1.0);
                continue;
            }
            int start = var_Id[querie[0]];
            int end = var_Id[querie[1]];
            if (start == end) {
                res.push_back(1.0);
                continue;
            }
            queue<pair<int, double>> q;                                    //  pair对应节点和路径值
            q.emplace(start, 1.0);
            bool found = false;                                            //  判断是否找到了正确的计算路径
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                int cur_node = cur.first;
                double weight = cur.second;
                if (cur_node == end) {
                    found = true;
                    res.push_back(weight);
                    break;
                }
                if (visited[cur_node]) continue;
                visited[cur_node] = true;
                
                for (auto neighbor: graph[cur_node]) {
                    int neighbor_node = neighbor.first;
                    double neighbor_weight = neighbor.second;
                    q.emplace(neighbor_node, weight * neighbor_weight);     //  用拷贝的节点保存路径积，每次计算请求会创建新的queue因此所有节点会被清空重新计算
                }
            }
            if (!found) res.push_back(-1.0);
        }
        return res;
    }
};