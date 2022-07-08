class MagicDictionary {
    unordered_map<string, int> hash_map;
    unordered_set<string> hash_set;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
    }

    vector<string> getNeibor(string s) {        //  生成一个string列表，里面是输入的单词word的广义邻居
        vector<string> res;
        for (int i = 0; i < s.size(); i++) {    //  遍历字符串中每个字符，将字符替换为*，生成每个广义邻居并将其存入hashmap中   
            char c = s[i];
            s[i] = '*';
            res.push_back(s);
            s[i] = c;
        }
        return res;
    }
    
    void buildDict(vector<string> dictionary) {
        for (string s: dictionary) {                // 遍历字典中的每个字符串
            hash_set.insert(s);
            for (string neibor: getNeibor(s)) {     // 求出每个字符串的广义邻居列表
                hash_map[neibor]++;
            }      
        }
    }
    
    bool search(string searchWord) {
        for (string neibor: getNeibor(searchWord)) {
            //  若当前单词的某个广义邻居数量大于1，说明字典中存在至少两个单词和当前单词相同或差一个字母(因为他们的某个广义邻居是相同的), 由于字典中单词不重复，所以必然有其中一个单词和当前单词差一个字母
            //  若当前单词的某个广义邻居数量等于1，则说明字典中存在一个单词和当前单词相同或差一个字母。那么我们需要先判断是否两个单词相同，如果不相同则互为广义邻居
            if (hash_map[neibor] > 1 || (hash_map[neibor] == 1 && !hash_set.count(searchWord))) return true;      
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */