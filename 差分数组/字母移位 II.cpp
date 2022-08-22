//  差分数组思路

class Solution {
public:
    string shiftingLetters(string& s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n + 1, 0);
        string ans = "";
        diff[0] = s[0] - 'a';
        for (int i = 1; i < n; i++) {            //  构建差分数组
            diff[i] = s[i] - s[i - 1];
        }
        //  每次对[start, end]位置的数据++或--
        for (auto shift: shifts) {
            int start = shift[0];
            int end = shift[1];
            int dir = shift[2];
            if (dir == 1) {
                diff[start] += 1;
                diff[end + 1] -= 1;
            } else {
                diff[start] -= 1;
                diff[end + 1] += 1;
            }
        }

        for (int i = 1; i < n; i++) {           //  通过差分数组还原原数组
            diff[i] += diff[i - 1];
        }
        for (int i = 0; i < n; i++) {
            diff[i] = (diff[i] % 26 + 26) % 26;
            ans.push_back(diff[i] + 'a');
        }
        return ans;
    }
};