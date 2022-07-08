class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> windows;
        int slow = 0, fast = 0;
        int max_len = INT_MIN;
        while (fast < s.size()) {
            windows[s[fast]]++;
            while (windows[s[fast]] > 1) {      // 说明找到了重复的字符
                windows[s[slow]]--;             // slow指针不断向前移动，直到找到重复的元素并将其删除
                slow++;
            } 
            max_len = max(max_len, fast - slow + 1);   //  此时窗口内不存在重复元素，长度为fast - slow + 1;
            fast++;     
        }
        
        return max_len == INT_MIN? 0: max_len;
    }
};