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




//  Prim算法的核心是，初始化创建无向图的邻接表，将第0个节点标记为遍历过，同时将0节点的包含其相邻节点和边权重的struct edge放入堆中，堆是最小堆，堆顶存放的元素是权重最小的边。当堆不为空时，我们不断地从堆中取出最小权重边，然后将边连接的节点标记为true，直至堆为空
//  最后判断是否每个节点都被遍历，若是则返回最小加权和。  需要注意的是每次将某个节点的相邻节点放入堆时，需要判断该节点是否已经被遍历，若是则跳过这次循环，从堆中取出元素的时候做同样的操作，防止出现环、

struct edge {           
    int to;
    int weight;
    edge(int _to, int _weight): to(_to), weight(_weight) {}
};

struct comp{
    bool operator()(edge& a, edge& b) {
        return a.weight > b.weight;
    }
};

class Prim {
    vector<vector<edge>> graph;                             //  无向加权图的邻接表
    vector<bool> inMST;                                     //  MST为最小生成树, 用于判断是否某个节点已经存在于最小生成树
    priority_queue<edge, vector<edge>, comp> heap;          //  用于动态找到最小权重边
public:
    int total_cost = 0;
    Prim(vector<vector<edge>>& _graph) {
        graph = _graph;
        inMST.resize(graph.size());
        inMST[0] = true;                                    //  我们从第0个节点开始
        cut(0);                                             //  将和0节点相邻的节点放到堆中，同时存入他们的权重
        while (!heap.empty()) {
            edge min_edge = heap.top();
            heap.pop();
            if (inMST[min_edge.to]) continue;
            inMST[min_edge.to] = true;
            total_cost += min_edge.weight;
            cut(min_edge.to);
        }
        for (int i = 0; i < inMST.size(); i++) {
            if (inMST[i] == 0) total_cost = -1;             // 如果某个节点不在图中，代表没有连接所有的节点
        }
    }

    void cut(int start) {      //  将和start相邻的节点放入堆中
        for (auto& edge: graph[start]) {
            int to = edge.to;
            if (inMST[to]) continue;                        //  如果该相邻节点已经在路径中，则跳过该节点防止成环
            heap.push(edge);
        }
    }
};


class Solution {
public:
    //  由于是无向加权图，所以邻接表中不能仅存放int类型表示to节点，还需要存放权重weight; 若不用struct则需要写成vector<vector<vector<int>>>, 最外面的vector代表邻接表，第二个vector代表每个节点相邻的节点, 最里面vector代表相邻的节点的下标及其权重
    vector<vector<edge>> buildGraph(int n, vector<vector<int>>& connections) {      
        vector<vector<edge>> graph(n);
        for (auto& connection: connections) {
            int from = connection[0] - 1;
            int to = connection[1] - 1;
            int weight = connection[2];
            graph[from].emplace_back(to, weight);       //  无向加权图
            graph[to].emplace_back(from, weight);    
        }
        return graph;
    }

    int minimumCost(int n, vector<vector<int>>& connections) {
        vector<vector<edge>> graph = buildGraph(n, connections);
        Prim* P = new Prim(graph);
        return P->total_cost;
    }
};