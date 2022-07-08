//  哈希表


class MapSum {
    unordered_map<string, int> map;                        //  记录要插入的字符串对应的值
    unordered_map<string, int> prefix;                     //  记录要插入的字符串的前缀串对应的值
public: 
    /** Initialize your data structure here. */
    MapSum() {
    }
    
    void insert(string key, int val) {
        int delta = val;
        if (map.count(key)) delta = val - map[key];         //  如果该键存在，那么它们有同样的前缀和，因此需要将前缀和中前一个键的值删除(-map[key])，然后将新加入的键值的值加入进去(val)
        map[key] = val;                                     //  更新字符串哈希表的值
        for (int i = 1; i <= key.length(); i++) {
            prefix[key.substr(0, i)] += delta;              //  更新加入的字符串的每一个前缀和，如果字符串之前不存在，则delta = val, 每个前缀和都加val; 若存在，则减掉前一个的值加上新的值(-map[key] + val)
        }
    }
    
    int sum(string prefix) {
        return this->prefix[prefix];
    }
};


//  前缀树

class TrieNode {
public:
    int val;
    vector<TrieNode*> child;
    TrieNode(): child(26), val(0) {}
    TrieNode(int _val): child(26), val(_val) {}
};


class MapSum {
    unordered_map<string, int> hash_map;            //  用于保存每个插入的字符串对应的值
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        int delta = val;
        if (hash_map.count(key)) delta = val - hash_map[key];           //  如果该键之前存在，则需要将该键的前缀串的值减去之前的值(hash_map[key])，然后加上新的键的值val
        hash_map[key] = val;                                            //  更新哈希表的键值对
        TrieNode* cur = root;
        for (char ch: key) {
            if (cur->child[ch - 'a'] == nullptr) cur->child[ch - 'a'] = new TrieNode(val);          //  如果节点不存在，则创建并初始化当前值val
            else cur->child[ch - 'a']->val += delta;                                                //  否则根据delta更新每个前缀串
            cur = cur->child[ch - 'a'];                                                             //  右移指针
        }
    }
    
    int sum(string prefix) {
        TrieNode* cur = root;
        for (char ch: prefix) {
            if (cur->child[ch - 'a'] == nullptr) return 0;
            cur = cur->child[ch - 'a'];
        }
        return cur->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */