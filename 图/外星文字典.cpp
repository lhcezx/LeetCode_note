//  拓扑排序，将前后每两个单词中找到第一个不相同的字母，然后按照顺序创建有向边，最后遍历图的每一个节点，进行拓扑排序，输出拓扑排序的后序遍历结果，将其反转
//  注意这里的输出字典序不唯一！！！输出任意一种即可

class Solution {
    unordered_map<char, vector<char>> graph;
    unordered_map<char, int> states;
    string dict = "";
    bool valid = true;                                                              //  判断是否有不合法的word排序存在
public:
    const int visiting = 1, visited = 2;
    void buildGraph(vector<string>& words) {
        for (auto word: words) {
            for (char c: word) {
                if (!graph.count(c)) graph[c] = vector<char>();                     //  给每个单词中的每个字母创建一个空的vector
            }
        }
        for (int i = 1; i < words.size(); i++) {
            string before = words[i - 1];
            string after = words[i];
            int len = min(before.length(), after.length());                         //  找到两个单词的公共部分
            int index = 0;
            while (index < len) {                                                   //  遍历单词公共部分
                char from = before[index];
                char to = after[index];
                if (from != to) {
                    graph[from].emplace_back(to);                                   //  找到了两个单词中第一个不相同的字母 
                    break;
                }     
                index++;
            }
            if (index == len && before.length() > after.length()) {                 //  如果前后单词公共部分相同，并且前面的单词比后面的单词长度长，则不符合排序要求，直接返回
                valid = false;
                return;
            }
        }
    }

    void traverse(char c) {
        if (!valid) return;
        if (!states.count(c)) {                         //  节点未被访问过
            states[c] = visiting;                       //  将状态设置为visiting;
            for (auto neighbor: graph[c]) {
                traverse(neighbor);
            }
        }
        else if (states[c] == visiting) {               //  回到了正在访问的节点，存在闭环
            valid = false;
            return;
        }
        else if (states[c] == visited) return;          //  该节点已经访问过了
        states[c] = visited;
        dict.push_back(c);                              //  拓扑排序一定是在后续遍历的位置添加节点，然后出去翻转
    }

    string alienOrder(vector<string>& words) {
        buildGraph(words);
        if (!valid) return "";                          //  判断是否存在公共部分相同的两个字符串，较长的排在前面的这种不合法存在
        // for (auto [from, to]: graph) {                  //  graph会根据添加from的顺序逐个遍历所有的from节点，由于from添加节点的顺序实际
        //     traverse(from);
        // }
        traverse(words[0][0]);
        if (!valid) return "";
        reverse(dict.begin(), dict.end());
        return dict;
    }
};