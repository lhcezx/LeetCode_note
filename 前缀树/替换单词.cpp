class Trie {
    vector<Trie*> child;
public: 
    Trie(): child(128) {}                   // constructor

    void insert(string& word) {
        Trie* node = this;                  //  this代表被实例化的类的当前对象, ex: Trie* example = new Trie()
        for (char ch: word) {               //  遍历要插入的单词的每个字母，如果字母已经存在则不插入，否则插入到当前节点的下一个节点中
            if (node->child[ch] == nullptr) node->child[ch] = new Trie();
            node = node->child[ch];
        }
        node->child['#'] = new Trie();      //  用#符号作为插入单词的结尾
    }

    string prefix(string& word) {
        Trie* node = this;
        string root = "";                                       //  用于保存词根
        for (char ch: word) {
            if (node->child['#'] != nullptr) return root;       //  说明在单词中找到了对应的完整词根
            if (node->child[ch] != nullptr) node = node->child[ch];         //  若单词和词根当前字母一致，则向后遍历一直到#
            else return word;                                   //  如果词根遍历未到#就出现单词与词根出现的字母不一致，则等于未找到词根，直接返回单词本身
            root.push_back(ch);
        }
        return root;                //  遍历结束，说明单词和词根相同，直接返回root
    }
};


class Solution {
    Trie* trie = new Trie();
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        for (string s: dictionary) {                                //  将每个词根插入到前缀树中，用#作为终止符
            trie->insert(s);
        }
        int i = 0;  
        string res = "";
        while (i < sentence.size()) {       
            string tmp = "";
            while (i < sentence.size() && sentence[i] != ' ') {     //  用空格分割单词
                tmp += sentence[i];
                i++;
            }
            res += trie->prefix(tmp);                               //  将单词替换为对应的最短词根
            res.push_back(' ');
            i++;                                                    //  越过空格
        }
        res.erase(res.size() - 1, 1);
        return res;
    }
};