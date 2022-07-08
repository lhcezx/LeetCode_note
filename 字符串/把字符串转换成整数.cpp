class Solution {
public:
    int strToInt(string str) {
        int first = 0;
        int last = str.size() - 1;
        long int res = 0, bndry = INT_MAX / 10;
        char sign;
        while (str[first] == ' ') first++;   // 去掉开头空格
        if (str[first] == '+' || str[first] == '-') sign = str[first], first++;
        if (!('0' <= str[first] && str[first] <= '9')) return 0;   // 若第一个遇到的字符不为数字，则返回0

        for (int i = first; i < str.size(); i++) {
            if (!('0' <= str[i] && str[i] <= '9')) break;  // 若数字断了，则返回
            if(res > bndry || (res == bndry && str[i] > '7')) {
                if (sign == '-') return INT_MIN;
                else return INT_MAX;
            }
            res = res * 10 + (str[i] - '0');
        }
        if (sign == '-') return -res;
        return res;
    }
};