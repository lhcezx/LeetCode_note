//  未优化版

class Solution {
    vector<vector<string>> res;
    vector<string> tmp;
    int n;
public:
    bool isPalindrome(string& s, int left, int right) {     //  判断该子串是否为回文串
        while (left <= right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    void backtrack(string& s, int start) {                  //  i代表我们所在的子串的启始位置
        if (start == n) res.push_back(tmp);                 //  当我们字串的启始位置到了最后一个字符，那么说明我们已经找到了一组回文子串 
        for (int end = start; end < n; end++) {             //  判断从i位置开始j位置结束的子串s[i, j]是否为回文串
            if (isPalindrome(s, start, end)) {              //  如果s[i, j]是回文串，那么我们判断从i = j + 1开始后面的子串
                tmp.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1);                      //  我们将j+1作为新的启始位置i来判断是否存在回文串
                tmp.pop_back();                             //  这里pop_back()的原因是我们的j在下一个循环会后移，我们要判断新的s[i, j]子串是否为回文，所以要将前面保存旧的s[i,j]删除
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.length();
        backtrack(s, 0);
        return res;
    }
};


//  记忆化回溯，将每个遍历到的子串s[i][j]是否是回文子串的结果保存到f[i][j]中，避免重复子问题

class Solution {
    vector<vector<string>> res;
    vector<string> tmp;
    vector<vector<int>> f;                                             //  记录s[i][j]是否为回文子串, 0代表没有遍历到, 1代表是, -1代表不是
    int n;
public:
    int isPalindrome(string& s, int left, int right) {                 //  判断该子串是否为回文串
        if (f[left][right]) return f[left][right];                     //  如果前面有保存过，那么直接返回保存的结果    
        if (left >= right) return f[left][right] = 1;                  //  每个单独的字母一定是回文子串，这里left > right的情况为当left + 1 > right - 1时，代表s[left] == s[right]，此时已经完成初始的[left, right]的判断，并且[left, right]为回文串，因此直接返回1，通过递归传参直到初始的left和right
        return f[left][right] = (s[left] == s[right]? isPalindrome(s, left + 1, right - 1): -1);
    }

    void backtrack(string& s, int start) {                             //  i代表我们所在的子串的启始位置
        if (start == n) res.push_back(tmp);                            //  当我们字串的启始位置到了最后一个字符，那么说明我们已经找到了一组回文子串 
        for (int end = start; end < n; end++) {                        //  判断从i位置开始j位置结束的子串s[i, j]是否为回文串
            if (isPalindrome(s, start, end) == 1) {                    //  如果s[i, j]是回文串，那么我们判断从i = j + 1开始后面的子串
                tmp.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1);
                tmp.pop_back();                                        //  这里pop_back()的原因是我们的j在下一个循环会后移，我们要判断新的s[i, j]子串是否为回文，所以要将前面保存旧的s[i,j]删除
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.length();
        f.assign(n, vector<int>(n));
        backtrack(s, 0);
        return res;
    }
};


//  动态规划初始化 + 回溯

class Solution {
    vector<vector<string>> res;
    vector<string> tmp;
    vector<vector<bool>> f;                                             //  记录s[i][j]是否为回文子串, 0代表没有遍历到, 1代表是, -1代表不是
    int n;
public:

    void backtrack(string& s, int i) {                                  //  i代表我们所在的子串的启始位置
        if (start == n) res.push_back(tmp);                             //  当我们字串的启始位置到了最后一个字符，那么说明我们已经找到了一组回文子串 
        for (int end = start; end < n; end++) {                         //  判断从i位置开始j位置结束的子串s[i, j]是否为回文串
            if (f[start][end]) {                                        //  如果s[i, j]是回文串，那么我们判断从i = j + 1开始后面的子串
                tmp.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1);
                tmp.pop_back();                                         //  这里pop_back()的原因是我们的j在下一个循环会后移，我们要判断新的s[i, j]子串是否为回文，所以要将前面保存旧的s[i,j]删除
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.length();
        f.assign(n, vector<bool>(n, 1));                    //  base case, f[i][j]中所有的当i >= j时, f[i][j] == 1;
        for (int i = n - 1; i >= 0; i--) {                  //  因此j从i + 1开始
            for (int j = i + 1; j < n; j++) {
                f[i][j] = (s[i] == s[j]? f[i + 1][j - 1]: 0);
            }
        }
        backtrack(s, 0);
        return res;
    }
};