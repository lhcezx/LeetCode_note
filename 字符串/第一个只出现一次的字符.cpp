class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> hash_map;
        for (char ch: s){
            ++hash_map[ch];
        }
        for(int i = 0; i < s.size(); i++){
            if (hash_map[s[i]] == 1) {
                return s[i];
            }
        }
        return ' ';
    }
};