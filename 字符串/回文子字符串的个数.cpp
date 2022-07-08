class Solution {
    int count = 0;
public:
    void CountPalindrome(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
            count++;
        }
    }
    int countSubstrings(string s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            CountPalindrome(s, i, i);
            CountPalindrome(s, i, i + 1);
        }
        return count;
    }
};