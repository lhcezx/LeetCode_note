class Solution {
public:
    int calculate(queue<char>& s) {
        int num = 0;
        char sign = '+';
        stack<int> stk;
        int res = 0;
        while (!s.empty()) {
            char cur = s.front();
            s.pop();
            if (isdigit(cur)) num = num * 10 + (cur - '0');
            if (cur == '(') num = calculate(s);
            if (!isdigit(cur) || s.empty()) {
                if (sign == '+') {
                    stk.push(num);
                } else if (sign == '-') {
                    stk.push(-num);
                } else if (sign == '*') {
                    int top = stk.top();
                    stk.pop();
                    stk.push(top * num);
                } else if (sign == '/') {
                    int top = stk.top();
                    stk.pop();
                    stk.push(top / num);                    
                }
                num = 0;
                sign = cur;
            }
            if (cur == ')') break;
        }

        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;
    }

    int calculate(string s) {
        queue<char> q;
        for (char c: s) q.push(c);
        return calculate(q);
    }
};