class TrieNode {
public:
    vector<TrieNode*> child;
    bool isEnd;
    TrieNode(): child(26), isEnd(false){}
};

class WordDictionary {
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* cur = root;
        for (char c: word) {
            if (cur->child[c - 'a'] == nullptr) cur->child[c - 'a'] = new TrieNode();
            cur = cur->child[c - 'a'];
        }
        cur->isEnd = true;
    }
    
    //  函数返回是否作为起始节点node的前缀树，存在从word[i]到word[n]这个字符串
    bool dfs(string& word, int i, TrieNode* node) {
        if (i == word.length()) return node->isEnd;
        char c = word[i];
        if (c != '.') {
            if (node->child[c - 'a'] != nullptr) return dfs(word, i + 1, node->child[c - 'a']);
        } else if (c == '.') {
            for (TrieNode* next: node->child) {                                      //  .可以代表任何一个字符，因此需要遍历每一个可能的字符
                if (next != nullptr && dfs(word, i + 1, next)) {                     //  检查字符的后缀部分是否与word[i]的后缀部分相同，若相同返回true;
                    return true;
                }
            }
        }
        return false;
    }

    bool search(string word) {
        TrieNode* cur = root;
        return dfs(word, 0, cur);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */