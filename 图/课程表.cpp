// BFS
class Solution {
public:
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto vec: prerequisites) {
            graph[vec[1]].push_back(vec[0]);          //  学习vec[1]课程之前需要先学习vec[0]课程
        }
        return graph;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        vector<int> indegree(numCourses);             //  用于统计每个节点的入度, 也就是有多少边指向这个节点 
        int count = 0;                                //  统计启始节点的数量

        for (vector<int> vec: prerequisites) {
            int from = vec[1], to = vec[0];           //  从from生成一条edges指向to, to的入度加一
            indegree[to]++;
        }

        for (int i = 0; i < numCourses; i++) {        //  遍历每一个节点的入度
            if (indegree[i] == 0) q.push(i);          //  如果某个节点的入度为0，则说明没有一条边会指向这个节点，因此该节点可以作为启始节点
        }

        while (!q.empty()) {
            int start = q.front();                    //  从队列中选择一个启始节点
            q.pop();
            count++;
            for (int node: graph[start]) {
                indegree[node]--;                     //  每个遍历到的相邻节点，都将其入度-1因为该路径已经遍历过
                if (indegree[node] == 0) q.push(node);      //  如果node的入度变为0，则说明指向node节点的路径已经遍历完毕，此时需要将node压入队列中，找从node为启始的节点
            }
        }
        return count == numCourses;
    }
};

// DFS
class Solution {
    vector<bool> visited;           //  用于判断该节点是否被访问过，如果一个节点被访问了，则说明和它相邻的所有节点一直到每条路径的尾部都会被访问，因此只要访问过了，就无需再次访问了
    vector<bool> onPath;            //  用于判断我们目前正在遍历的路径
    bool hasCycle = false;
public:
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {       //  首先根据prerequiestes创建邻接表，构成有向图
        vector<vector<int>> graph;
        graph.resize(numCourses);
        for (auto vec: prerequisites) {
            graph[vec[1]].push_back(vec[0]);                                                   //  vec[1]代表先修课程，vec[0]代表后修课程
        }
        return graph;
    }

    void traverse(vector<vector<int>>& graph, int start) {      //  以start节点为启始点开始遍历
        if (onPath[start]) hasCycle = true;                     //  代表我们当前遍历的路径中有环
        if (visited[start] || hasCycle) return;                 //  若当前节点已经被遍历过，或者发现存在有环，则return
        
        visited[start] = true;                                  //  代表当前节点start以及它的相邻节点已经全部被访问过了(因为后面紧跟这就是完整的for循环)
        onPath[start] = true;                                   //  代表我们目前正在遍历这条路径
        for (int t: graph[start]) {                             //  遍历当前节点course的相邻节点
            traverse(graph, t);                                
        }
        onPath[start] = false;                                  //  离开节点时，需要将其还原为false
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses);
        onPath.resize(numCourses);
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        for (int i = 0; i < numCourses; i++) {                   //  这里需要使用for循环遍历每个节点，因为有可能节点的路径中完全不包含其中某些节点，因此我们必须访问每个节点的邻接节点
            traverse(graph, i);  
        }
        return !hasCycle;
    }
};