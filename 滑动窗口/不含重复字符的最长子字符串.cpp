class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int max_len = 1;
        vector<int> cnt(128);
        int slow = 0, fast = 0;
        while (fast < s.length()) {
            if (slow < fast && cnt[s[fast]] != 0) {     //  当s[fast]字符重复时，slow指针右移
                cnt[s[slow]]--;
                slow++;
            } else if (slow < fast && cnt[s[fast]] == 0){
                cnt[s[fast]]++;
                max_len = max(max_len, fast - slow + 1);
                fast++;
            } else {                                    //  当slow与fast相遇的时候
                if (cnt[s[fast]] == 0) cnt[s[fast]]++;  //  如果是开头(slow = fast = 0) 那么cnt[s[fast]]++。如果字符串中间相遇，则cnt[s[fast]]已经++过了，fast指针继续向前即可
                fast++;
            }
        }
        return max_len;
    }
};