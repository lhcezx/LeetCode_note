class Trie {
    bool isEnd;
    vector<Trie*> child;
public:
    /** Initialize your data structure here. */
    Trie(): isEnd(false), child(26) {}
    
    Trie* search_word(string word) {
        Trie* node = this;
        for (char ch: word) {
            ch -= 'a';
            if (node->child[ch] == nullptr) return nullptr;           //  如果为null则说明没有以ch-'a'开头的单词
            node = node->child[ch];
        }
        return node;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char ch: word) {
            ch -= 'a';
            if (node->child[ch] == nullptr) node->child[ch] = new Trie();  //  如果我们要找到的字母在树中不存在，则创建一根树枝 new Trie(). 注意括号内存放的值是节点，而键[ch - 'a‘]代表树枝
            node = node->child[ch];           //  将指针移动到新创建的节点上
        }
        node->isEnd = true;
    }
 
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (search_word(word) != nullptr && search_word(word)->isEnd == true) return true;
        return false; 
    }

    bool startsWith(string prefix) {
        if (search_word(prefix) != nullptr) return true;
        return false;
    }

};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */