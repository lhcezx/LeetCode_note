//  贪心思路，从左向右遍历，记录左括号和右括号出现的次数，当次数相等时增加括号对数，当右括号大于左括号时出现非法情况，计数器清零. 但仅仅这样无法解决类似 "((()" 的情况，因为右括号始终小于左括号数量
//  解决方法就是从左向右遍历后，再从右向左遍历一遍，然后记录最大的括号对数即可

class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0, left = 0, right = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) max_len = max(max_len, 2 * left);
            if (left < right) {
                left = 0;
                right = 0;
            }
        }
        left = 0, right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) max_len = max(max_len, 2 * left);
            if (left > right) {
                left = 0;
                right = 0;
            }            
        }
        return max_len;
    }
};