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