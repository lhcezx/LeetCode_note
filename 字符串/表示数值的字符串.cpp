//  需要注意的是e或E前面必然跟着数字，且后面不能有小数点
//  正负号只出现在数字开头或紧跟在e后


class Solution {
public:
    bool isNumber(string s) {
        if (s == " ") return false;
        bool isnum = false, isE = false, isdot = false;
        int first = 0;
        int last = s.size() - 1;
        while (s[first] == ' ') first++;        // 去掉数字前空格
        while (s[last] == ' ') last--;          // 去掉数字后空格
        for (int i = first; i <= last; i++) {
            if ('0' <= s[i] && s[i] <= '9') isnum = true;        //  记录数字的存在
            else if (s[i] == '+' || s[i] == '-') {               //  判断是否为正负号
                if (i != first && s[i-1] != 'e' && s[i-1] != 'E') return false;      //  若为正负号，判断其位置是否为首位或前面是否有e
            }
            else if (s[i] == 'e' || s[i] == 'E') {
                if (isE || !isnum) return false;    //  如果e已经出现过或E前面没有出现数字，则出错
                isE = true;                         //  代表出现过e并持续标记
                isnum = false;                      //  重新标记数字, 判断e后是否有跟数字
            }
            else if (s[i] == '.') {                      //  如果第i位为小数点
                if (isdot || isE) return false;         //  如果已经出现过小数或已经出现过e或前面没有数字
                isdot = true;
            } 
            else return false;
        }
        return isnum;
    }
};