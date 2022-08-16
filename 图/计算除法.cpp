//  双向有权图，BFS。将每个字符串变量映射成Id用来构成节点，用除法计算结果values代表两个节点的边的权重，每次计算请求queries[0]就是起点，quieries[1]是终点，计算之间的路径权重乘积

typedef pair<string, double> edge;

class Solution {
    unordered_map<string, vector<edge>> graph;
    unordered_set<string> set;                                  //  用于判断节点是否存在在途中
public:
    void buildGraph(vector<vector<string>>& equations, vector<double>& values) {
        for (int i = 0; i < equations.size(); i++) {
            string from = equations[i][0];
            string to = equations[i][1];
            double value = values[i];
            graph[from].emplace_back(to, value);                //  用哈希表保存节点和边的权重，注意是双向边
            graph[to].emplace_back(from, 1.0 / value);
            if (!set.count(from)) set.insert(from);
            if (!set.count(to)) set.insert(to);

        }   
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        buildGraph(equations, values);
        for (auto querie: queries) {
            string from = querie[0];
            string to = querie[1];
            if (!set.count(from) || !set.count(to)) {           //  判断变量是否合法
                res.push_back(-1.0);
                continue;
            }
            unordered_map<string, bool> visited;                //  每次请求都需要一个新的visited
            bool found = false;
            queue<edge> q;
            q.push({from, 1.0});                                //  q需要同时记录当前节点和当前路径积
            while (!q.empty()) {
                auto [node, cur_prod] = q.front();              //  节点和路径积
                if (node == to) {
                    found = true;
                    res.push_back(cur_prod);
                    break;
                }
                q.pop();
                for (auto neighbor: graph[node]) {
                    string next = neighbor.first;
                    double weight = neighbor.second;
                    if (visited[next]) continue;
                    visited[next] = true;
                    q.push({next, cur_prod * weight});
                }
            }
            if (!found) res.push_back(-1.0);                    //  如果遍历完所有节点也没有找到，则压入-1.0
        }
        return res;
    }
};