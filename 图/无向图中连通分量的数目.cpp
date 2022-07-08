class UnionFind {
    vector<int> parent;             //  记录每个节点的父节点
public:
    int count;                      //  记录连通分量的数目
    UnionFind(int n) {
        count = n;
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;                  //  每个节点的父节点都是自身，此时连通分量为节点数量n
        }
    }

    void Union(int i, int j) {
        int root_i = Find(i);
        int root_j = Find(j);
        if (root_i == root_j) return;       //  代表这两个节点已经在同一个集合中了，因为他们有共同的根节点，因此无需和并
        parent[root_i] = root_j;            //  将两个根节点连通起来，相当于合并子树。因为如果i和j连通，又因为i和root_i连通，则相当于root_i和j连通，同时也相当于root_i和root_j连通
        count--;                            //  减少了一个连通分量
        
    } 

    int Find(int i) {                       //  找到某个节点的根节点，也就是能代表它存在的集合的那个最终节点
        if (parent[i] != i) {            //  只有根节点的父节点为它本身
        //  递归函数一直遍历到根节点，然后返回根节点，回溯到每一层也就是树的每一个节点，让每个节点的父指针都指向最终的根节点，相当于将树展平，路径压缩     
            parent[i] = Find(parent[i]);    //  找到根结点并返回，同时将整棵树上每个节点的父节点都修改为根节点
        }     
        return parent[i];                   
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind* UF = new UnionFind(n);
        for (auto edge: edges) {
            UF->Union(edge[0], edge[1]);
        }
        return UF->count;
    }   
};