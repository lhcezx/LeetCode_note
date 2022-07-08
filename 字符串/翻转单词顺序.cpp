class Solution {
public:
    string reverseWords(string s) {
        int i = s.length() - 1, j;
        string res;
        while (i >= 0) {
            while (i >= 0 && s[i] == ' ') i--;
            j = i;
            while (i >= 0 && s[i] != ' ') i--;
            res.append(s.substr(i + 1, j - i));
            res.push_back(' ');
        }
        while (res.back() == ' ') res.pop_back();
        return res;
    }
};