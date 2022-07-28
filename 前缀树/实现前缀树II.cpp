class Trie {
    vector<Trie*> child;
    int counter = 1;
public:
    Trie() {
        child.assign(26, nullptr);
    }
    
    void insert(string word) {
        Trie* cur = this;
        for (char c: word) {
            if (cur->child[c - 'a'] != nullptr) cur->child[c - 'a']->counter++;     
            else cur->child[c - 'a'] = new Trie();
            cur = cur->child[c - 'a'];
        }
    }
    
    int countWordsEqualTo(string word) {
        int res = 0;
        Trie* cur = this;
        for (char c: word) {
            if (cur->child[c - 'a'] == nullptr) return res;
            cur = cur->child[c - 'a'];
        }
        res = cur->counter;
        for (auto next: cur->child) {
            if (next != nullptr) res -= next->counter;
        }
        return res;
    }
    
    int countWordsStartingWith(string prefix) {
        Trie* cur = this;
        for (char c: prefix) {
            if (cur->child[c - 'a'] == nullptr) return 0;
            cur = cur->child[c - 'a'];
        }
        return cur->counter;
    }
    
    void erase(string word) {
        Trie* cur = this;
        for (char c: word) {
            if (cur->child[c - 'a'] != nullptr) cur->child[c - 'a']->counter--;
            cur = cur->child[c - 'a'];
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */