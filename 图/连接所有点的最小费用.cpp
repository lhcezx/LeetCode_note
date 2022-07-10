// Kruskal最小生成树算法，并查集 + 贪心

class UnionFind {
    vector<int> parent;
public:
    int count;
    UnionFind(int n) {
        count = n;
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void Union(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i == root_j) return;
        parent[root_i] = root_j;
        count--;
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }
};


int cost(vector<int>& x, vector<int>& y) {          //  计算两点之间的费用
    return abs(x[0] - y[0]) + abs(x[1] - y[1]);
}


struct edge {                                       //  定义边的类型
    int i;
    int j;
    int cost;
    edge(int _i, int _j, int _cost) {
        i = _i;
        j = _j;
        cost = _cost;
    } 
};


bool compare(edge& x, edge& y) {
    return x.cost < y.cost;
}


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int total_cost = 0;
        vector<edge> edgesWithCost;
        UnionFind* UF = new UnionFind(points.size());
        for (int i = 0; i < points.size(); i++) {                       //  遍历所有的点，计算它们之间的费用
            for (int j = i + 1; j < points.size(); j++) {
                edgesWithCost.emplace_back(i, j, cost(points[i], points[j]));
            }
        }
        
        sort(edgesWithCost.begin(), edgesWithCost.end(), compare);      //  排序
        for (auto& edge: edgesWithCost) {                               
            if (UF->count == 1) break;                                  //  连通分量为1，代表构成一条路径
            if (UF->connected(edge.i, edge.j)) continue;                //  如果两个点已经连通，则不需要再次连通，否则会形成环
            UF->Union(edge.i, edge.j);
            total_cost += edge.cost;
            
        }
        return total_cost;
    }
};


//  Prim算法

struct edge {
    int to;
    int weight;
    edge(int _to, int _weight): to(_to), weight(_weight) {}
};

struct comp {                           //  小顶堆
    bool operator()(edge& a, edge& b) {
        return a.weight > b.weight;     //  true时将a排在b前面，heap.top()返回heap中的最后一个元素，也就是最小的元素
    }
};


class Prim {
    vector<vector<edge>> graph;
    vector<bool> inMST;
    priority_queue<edge, vector<edge>, comp> heap;
    
public:
    int total_cost = 0;
    Prim(vector<vector<edge>> _graph) {
        graph = _graph;
        inMST.resize(graph.size());
        inMST[0] = 1;
        cut(0);
        while (!heap.empty()) {
            edge min_edge = heap.top();
            heap.pop();
            if (inMST[min_edge.to]) continue;                     //  如果这个节点已经遍历过
            inMST[min_edge.to] = true;
            total_cost += min_edge.weight;
            cut(min_edge.to);
        }
        for (int i = 0; i < inMST.size(); i++) {                  //  确保整个图中每个节点都被遍历到
            if (inMST[i] == 0) total_cost = -1;
        }

    }

    void cut(int start) {
        for (edge& edge: graph[start]) {
            if (inMST[edge.to]) continue;
            heap.push(edge);
        }
    }
};


class Solution {
public:

    int dist(vector<int>& a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    vector<vector<edge>> buildGraph(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<edge>> graph(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int from = i;
                int to = j;
                int d = dist(points[i], points[j]);
                graph[from].emplace_back(to, d);                //  无向加权图
                graph[to].emplace_back(from, d);
            }
        }
        return graph;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<edge>> graph = buildGraph(points);
        Prim* P = new Prim(graph);
        return P->total_cost;
    }
};



