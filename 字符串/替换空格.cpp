class Solution {
public:
    string replaceSpace(string s) {
        while(s.find(' ')!= string::npos){
            s.replace(s.find(' '), 1, "%20");
        }
        return s;
    }
};