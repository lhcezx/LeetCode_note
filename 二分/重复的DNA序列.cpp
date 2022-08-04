class Solution {
    unordered_map<string, int> hash_map;       //  统计每个序列出现的次数
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int n = s.size();
        string tmp = "";
        
        for (int i = 0; i < 10; i++) {
            tmp.push_back(s[i]);
        }
        hash_map[tmp]++;
        int fast = 10;
        while (fast < n) {
            tmp.push_back(s[fast]);
            tmp.erase(0, 1);
            hash_map[tmp]++;
            if (hash_map[tmp] == 2) res.push_back(tmp);            //  如果出现的次数等于2次
            fast++;
        }
        return res;
    }
};