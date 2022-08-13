//  哈希表
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hash_map;
        for (string c: strs) {
            string tmp(26, '0');            //  初始化一个对比字符串tmp
            for (char a: c) {
                tmp[a - 'a']++;
            }
            hash_map[tmp].push_back(c);     //  相同的变为词会对应同样的tmp, 因此将所有tmp相同的string存到vector<string>中，也就是Hash_map的值中
        }
        for (auto tmp: hash_map) {
            res.push_back(tmp.second);
        }
        return res;
    }
};


//  计数法
//  用每个字符串中每个字母出现的次数表作为键
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hash_map;
        for (string str: strs) {
            string tmp = string(26, '0');
            for (char c: str) {
                tmp[c - 'a']++;
            }
            hash_map[tmp].push_back(str);           //  出现相同字母次数的字符会放在同一个键中
        }
        for (auto cur: hash_map) {
            res.push_back(cur.second);
        }
        return res;
    }
};