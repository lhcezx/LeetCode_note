class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s1;

        for (string c: tokens) {
            if (c != "+" && c != "-" && c != "*" && c != "/") s1.push(stoi(c));
            else {
                int i = s1.top();
                s1.pop();
                int j = s1.top();
                s1.pop();
                if (c == "+") s1.push(j + i);
                else if (c == "-") s1.push(j - i);
                else if (c == "*") s1.push(j * i);
                else if (c == "/") s1.push(j / i);
            }  
        }
        return s1.top();
    }
};