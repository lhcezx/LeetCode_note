class Solution {
public:
    int calculate(queue<char>& s) {
        int res = 0;
        stack<int> stk;
        int num = 0;
        char sign = '+';
        while (!s.empty()) {
            char cur = s.front();
            s.pop();
            //  字符串转数字
            if (isdigit(cur)) {
                num = num * 10 + (cur - '0');
            }
            //  进入递归
            if (cur == '(') {
                calculate(s);
            }
            //  将数字压入栈并重置数字为0，保存sign
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
            //  递归终止条件
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
        //  去掉空格
        for (char c: s) {
            if (c != ' ') q.push(c);
        }
        return calculate(q);
    }
};