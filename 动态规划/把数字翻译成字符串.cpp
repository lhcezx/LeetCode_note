class Solution {
public:
    int translateNum(int num) {
        int fn = 1, fn_1 = 1, fn_2 = 1;
        string tmp = to_string(num);
        for (int i = 1; i < tmp.length(); i++) {
            if ("10" <= tmp.substr(i-1, 2) && tmp.substr(i-1, 2) <= "25"){
                fn = fn_1 + fn_2;
            } else {
                fn = fn_1;
            }
            fn_2 = fn_1;
            fn_1 = fn;     
        }
        return fn;
    }
};