//  模拟，当s[i]为0, s[i + 1]为1的时候，将两者字符交换，并将i指针后移两位，移动一位的话否则可能会导致s[i+1]和后面的s[i+2]交换位置
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int time = 0;
        int n = s.length();
        bool find = false;
        while (true) {
            find = false;
            for (int i = 0; i < n;) {
                if (s[i] == '0' && s[i + 1] == '1') {
                    s[i] = '1';
                    s[i + 1] = '0';
                    i += 2;
                    find = true;
                } else {
                    i += 1;
                }
            }
            if (find) time++;
            else return time;
        }
    }
};