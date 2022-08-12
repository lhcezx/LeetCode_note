//  动态平衡法
class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        int need = 0;                     //  需要右括号对的数量
        for (int i = 0; i < s.length();) {
            if (s[i] == '(') {
                need += 1;
                i++;
            } else {
                need--;
                if (need == -1) {         //  右括号出现的数量过多，需要添加一个左括号平衡右括号
                    res++;
                    need = 0;
                }
                if (i + 1 >= s.length() || s[i + 1] != ')') {          //  如果出现的右括号不连续，则需要添加右括号
                    res++;
                    i++;
                } else {                                               //  若连续，则跳过第i和第i+1个右括号
                    i += 2;
                }
            }
        }
        return res + need * 2;
    }
};



//  动态平衡法

class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        int need = 0;                     //  需要右括号的数量
        for (char c: s) {
            if (c == '(') {
                need += 2;
                if (need % 2 == 1) {
                    res++;                //  若需求量为奇数，则说明前面出现的右括号不以偶数对出现，应当添加右括号使得右括号以偶数对形式与左括号匹配
                    need--; 
                }
            } else {
                need--;
                if (need == -1) {         //  多出来一个右括号，需要添加左括号，同时右括号需求量变为1
                    res++;
                    need = 1;
                }
            }
        }
        return res + need;
    }
};