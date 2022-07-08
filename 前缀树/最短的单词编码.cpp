//  哈希表

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans = 0;
        unordered_set<string> hash_set(words.begin(), words.end());
        for (auto word: words) {
            for (int i = 1; i < word.size(); i++) {
                hash_set.erase(word.substr(i));                         //  将单词数组中的单词的每个后缀都遍历一次，如果存在于哈希集合中，则将其删除
            }
        }
        for (string s: hash_set) {
            ans += s.size() + 1;
        }
        return ans;
    }
};


//  前缀树

class Trie_node {
    vector<Trie_node*> child;
public:
    int count = 0;
    Trie_node(): child(26) {}
    Trie_node* get(char c) {
        if (child[c - 'a'] == nullptr) {
            child[c - 'a'] = new Trie_node();
            count++;                            //  如果该节点的子节点没被访问，则将该节点标记为1，并创建子节点，因此当我们遍历完一个单词，最后一个字母的节点是没有被标记为1的；
        }
        return child[c - 'a'];
    }
};



class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<Trie_node*, int> hash_map;
        Trie_node* node = new Trie_node();
        for (int i = 0; i < words.size(); i++) {                //  遍历每一个单词
            Trie_node* cur = node;
            string s = words[i];
            for (int j = s.size() - 1; j >= 0; j--) {           //  倒叙遍历每一个单词的字母
                cur = cur->get(s[j]);
            }
            hash_map[cur] = i;                                  //  记录每个单词的最后一个节点和单词在words中的下标
        }
        int ans = 0;
        for (auto val: hash_map) {                              //  遍历哈希表，如果单词最后一个节点没有被标记为1，则说明该单词不为后缀单词，根据下标找到单词的长度并加1
            if (val.first->count == 0) ans += words[val.second].length() + 1;
        }
        return ans;
    }
};