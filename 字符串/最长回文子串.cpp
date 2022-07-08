class Solution {
public:
    // 双指针问题，从字符串的某个中心位置向两边移动。
    // 该函数用与找到从l位置向左和从r位置向右的最长回文串。若l = r则代表我们找的是奇数长度回文串，若l+1 = r则代表寻找偶数长度的回文串
    string palindrome(string s, int l, int r) {   
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
    string longestPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.length(); i++) {      //  遍历字符串的每一个位置
            res = res.length() > palindrome(s, i, i).length() ? res: palindrome(s, i, i);
            res = res.length() > palindrome(s, i, i+1).length() ? res: palindrome(s, i, i+1);
        }
        return res;
    }
};