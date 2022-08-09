class Solution {
public:
    int calculate(queue<char>& s) {
        stack<int> stk;
        int res = 0;
        int n = s.size();
        int num = 0;
        char sign = '+';
        while (!s.empty()) {
            char cur = s.front();
            s.pop();              //  获取第一个字符后将其删除, 目的是为了递归传参直接传修改后的字符串
            if (isdigit(cur)) {                                     
                num = num * 10 + (cur - '0');
            }
            //  注意左括号判别式要放在中间，不用担心左右括号会被记在sign里面，因为在碰到括号前一定会先遇到计算符，因此递归结束的结果会被正确的放入栈内，然后在右括号后也一定会跟计算符号，所以左右括号由于在下面的if中不存在判断，因此会直接跳过
            if (cur == '(') {
                num = calculate(s);                                
            }
            if (!isdigit(cur) || s.empty()) {      //  若不是数字或指针走到字符串最后一个字符，则需要将计算的数字配合sign放入栈，并将数字清零
                if (sign == '+') {
                    stk.push(num);
                } else if (sign == '-') {
                    stk.push(-num);
                }
                sign = cur;
                num = 0;
            }
            //  注意右括号判别式要放最后，因为当遇到右括号，我们需要首先把前面计算的数字放入栈内，再结束循环
            if (cur == ')') break;
        }
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        return res;        
    }

    //  返回字符串s表达式计算的数值
    int calculate(string s) {
        queue<char> q;
        //  删掉字符串中的空格
        for (int i = 0; i < s.size(); i++) {            
            if (s[i] != ' ') q.push(s[i]);
        }
        return calculate(q);
    }
};