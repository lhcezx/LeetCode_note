//  超时版

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        int steps = 1;                                              //  beginWord让启始序列长度为1
        int counter = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front();
                if (cur == endWord) return steps;
                q.pop();
                for (auto& word: wordList) {
                    counter = 0;
                    if (visited.count(word)) continue;
                    for (int k = 0; k < beginWord.length(); k++) {  //  遍历每一个单词，记录相同字母的个数
                        if (cur[k] == word[k]) counter++;
                    }
                    if (counter == word.size() - 1) {               //  代表两个单词只有一个字母不相同，可以在下一步进行转换
                        q.push(word);
                        visited.insert(word);
                    }
                }

            }
            steps++;
        }
        return 0;
    }
};


//  建图优化版
//  将每个单词创建其广义邻居，并将每个单词初始化一个id, 然后根据id构建邻接表

class Solution {
public:
    unordered_map<string, int> wordId;              //  单词与id的映射
    vector<vector<int>> graph;                      //  邻接表
    vector<bool> visited;
    int numWords = 0;
    //  创建一个单词和id的哈希映射，并将该单词(节点)在邻接表中初始化一个位置
    void addWord(string& word) {                     
        if (wordId.count(word)) return;
        wordId[word] = numWords++;                  //  如果不在哈希表中，那么给这个单词初始化一个id
        graph.emplace_back(vector<int>());          //  给这个单词(节点)在邻接表中初始化一个位置
    }

    //  为每个单词和它的广义邻居创建一条边
    void addEdges(string& word) {
        addWord(word);
        int word_id = wordId[word];
        for (char& c: word) {
            char tmp = c;
            c = '*';                                //  将单词的每一个字母分别替换成*
            addWord(word);
            int neighbor_id = wordId[word];
            graph[word_id].push_back(neighbor_id);  //  在邻接表中创建单词和其广义邻居的边
            graph[neighbor_id].push_back(word_id);  //  这里的边是无向边，如果不是无向边的话，例如hit和h*t，hot和h*t，如果每个单词只单向连接原单词和广义邻居，则hit是没法走到hot的
            c = tmp;                                //  将word还原
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int steps = 0;
        addEdges(beginWord);                
        for (string word:wordList) {                //  将字典中每一个单词创建与广义邻居的无向边
            addEdges(word);
        }
        visited.assign(numWords, false);
        if (!wordId.count(endWord)) return 0;               
        queue<int> q;
        q.push(wordId[beginWord]);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int cur = q.front();
                q.pop();
                if (visited[cur]) continue;
                visited[cur] = true;
                if (cur == wordId[endWord]) return steps / 2 + 1;           //  由于广义邻居的出现导致每个单词的前面都会多出广义邻居节点(除了初始节点外) 因此总步数需要/2最后再加上第一个开头的单词
                for (int neighbor: graph[cur]) {
                    q.push(neighbor);
                }
            }
            steps++;
        }
        return 0;
    }
};

