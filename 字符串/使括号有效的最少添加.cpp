//  本题通过left记录左括号出现的次数，当右括号出现时left--, 当left等于负一时添加左括号res++后将右括号平衡。实现左右括号动态平衡，否则若出现 ))))))(((((( 情况算法仅仅判断左右括号数量相同不需要添加括号，但实际上需要首先平衡掉前面的右括号通过res, 再最后平衡掉剩余的左括号left -> res + left;
class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0;                    //  记录添加左括号平衡多出来的右括号的操作数
        int left = 0;                   //  用来记录当前平衡后的左括号出现的次数
        for (char c: s) {
            if (c == '(') {             //  出现左括号时left++，出现右括号时left--
                left++;
            } else {
                left--;
                if (left == -1) {       //  当left == -1说明多出来一个右括号，右括号太多了，此时我们需要添加左括号来平衡数量，将left重置为0
                    left = 0;
                    res++;
                }
            }
        }
        return res + left;
    }
};