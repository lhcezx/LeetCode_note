class Solution {
public:
    string plusOne(string cur, int pos) {
        if (cur[pos] == '9') cur[pos] = '0';
        else cur[pos] += 1;
        return cur;
    }

    string minusOne(string cur, int pos) {
        if (cur[pos] == '0') cur[pos] = '9';
        else cur[pos] -= 1;
        return cur;
    }

    int BFS(vector<string>& deadends, string target) {
        int step = 0;
        unordered_set<string> dead(deadends.begin(), deadends.end());             //  触发deadends
        unordered_set<string> visited;                          //  数字是否被访问过
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {                      //  对每一层的结果进行遍历，每层都多拨一个数字
                string cur = q.front();
                q.pop(); 
                if (dead.count(cur)) continue;                  //  如果在死亡数字名单中
                if (cur == target) return step;
                for (int j = 0; j < 4; j++) {
                    string p1 = plusOne(cur, j);
                    if (!visited.count(p1)) {                   //  如果未被访问过  
                        visited.insert(p1);                     //  visited.insert必须设置每个新节点的入队时，否则例如1000和0100都会产生1100, 那么1100会入两次队造成重复
                        q.push(p1);
                    }          
                    string m1 = minusOne(cur, j);
                    if (!visited.count(m1)) {
                        visited.insert(m1);       
                        q.push(m1);    
                    }  
                }
            }
            step++;
        }
        return -1;
    }
    int openLock(vector<string>& deadends, string target) {
        return BFS(deadends, target);
    }

};