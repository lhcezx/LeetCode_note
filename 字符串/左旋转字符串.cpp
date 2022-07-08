class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string substr = s.substr(0, n);
        s.erase(0, n);
        s.insert(s.length(), substr);
        return s;
    }
};