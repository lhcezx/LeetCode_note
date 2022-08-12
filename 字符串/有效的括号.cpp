//  将所有左括号添加到栈内，遇到右括号时弹出栈顶元素比对是否为同一类型括号
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') stk.push(c);
            else {
                if (!stk.empty()) {
                    char top = stk.top();
                    stk.pop();
                    if (top == '(' && c != ')') return false;
                    if (top == '[' && c != ']') return false;
                    if (top == '{' && c != '}') return false;
                } else return false;
            }
        }
        return stk.empty();
    }
};