//  递归解法
class Solution {
public:
    //  decode返回从start开始到结尾的解码字符串
    string decode(string& s, int& start) {
        string res = "";
        int n = s.length();
        if (start == n) return "";
        int nums = 0;
        for (int i = start; i < n;) {
            char c = s[i];
            if (isdigit(c)) {
                nums = nums * 10 + (c - '0');
                i++;
            } else if (c == '['){                       //  碰到左括号，i++跳过左括号，进入递归并返回括号内解码的字符串
                i++;
                string tmp = decode(s, i);
                for (int k = 0; k < nums; k++) {        //  将解码的字符串重复nums次
                    res += tmp;
                }
                nums = 0;
            } else if (c == ']'){                       //  遇到右括号，前进一步跳过右括号并终止递归，返回字符串
                i++;
                start = i;
                break;
            } else {
                res += c;
                i++;
            }
        }
        return res;
    }

    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
};



//  双栈

class Solution {
public:
    string decodeString(string s) {
        stack<int> stk_num;
        stack<string> stk_str;
        string cur = "";
        string res = "";
        int num = 0;
        for (int i = 0; i < s.length(); i++){
            if (isdigit((s[i]))) {                 
                num = num * 10 + (s[i] - '0');
            } else if (isalpha(s[i])) {
                cur += s[i];
            } else if (s[i] == '[') {               //  当遇到左括号时，将括号前面记录的数字入栈，将括号前面记录的字符也入栈. ex: abc12[, str = abc, num = 12.
                stk_num.push(num);
                stk_str.push(cur);
                num = 0;
                cur = "";
            } else if (s[i] == ']') {               //  当遇到右括号时，将数字栈栈顶元素k弹出，同时将当前记录的cur重复k次，并累加在字符串栈的栈顶元素后面. ex: a[3[c]] -> 栈顶元素accc
                int tmp = stk_num.top();
                stk_num.pop();
                for (int i = 0; i < tmp; i++) {
                    stk_str.top() += cur;
                }
                cur = stk_str.top();                //  同时将栈顶元素赋值给cur，然后将字符串栈顶元素出栈, 为的是后面的右括号继续做同样的操作
                stk_str.pop();
            }
        }
        res += cur;
        return res;
    }
};