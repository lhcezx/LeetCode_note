// DFS
class Solution {
    bool hasCycle = false;
    vector<bool> visited;
    vector<bool> onPath;
    vector<int> res;
public:
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& vec: prerequisites) {
            graph[vec[1]].push_back(vec[0]);                    //  需要完成vec[1]课程，首先需要完成vec[0]课程. 创建邻接表
        }
        return graph;
    }

    void traverse(vector<vector<int>>& graph, int start) {
        if (onPath[start]) hasCycle = true;
        if (visited[start] || hasCycle) return;
        visited[start] = true;
        onPath[start] = true;
        for (int t: graph[start]) {
            traverse(graph, t);
        }
        onPath[start] = false;
        res.push_back(start);                                  //  后续遍历，相当于从最后一个尾节点推入的，所以最后返回以后需要reverse一下
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses);
        onPath.resize(numCourses);
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        for (int i = 0; i < numCourses; i++) {
            traverse(graph, i);
        }
        if (hasCycle) {
            return vector<int>();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

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

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        vector<int> indegree(numCourses);             //  用于统计每个节点的入度, 也就是有多少边指向这个节点 
        vector<int> res;
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
            res.push_back(start);                     //  每个遍历到的节点存到一起就是一条完整的路径
            for (int node: graph[start]) {
                indegree[node]--;                     //  每个遍历到的相邻节点，都将其入度-1因为该路径已经遍历过
                if (indegree[node] == 0) q.push(node);      //  如果node的入度变为0，则说明指向node节点的路径已经遍历完毕，此时需要将node压入队列中，找从node为启始的节点
            }
        }
        if (count == numCourses) return res;
        else return vector<int>();
    }
};